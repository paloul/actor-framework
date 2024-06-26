// This file is part of CAF, the C++ Actor Framework. See the file LICENSE in
// the main distribution directory for license terms and copyright or visit
// https://github.com/actor-framework/actor-framework/blob/master/LICENSE.

#include "caf/test/fixture/deterministic.hpp"
#include "caf/test/test.hpp"

#include "caf/anon_mail.hpp"
#include "caf/event_based_actor.hpp"

#include <atomic>
#include <condition_variable>
#include <mutex>

CAF_PUSH_DEPRECATED_WARNING

using namespace caf;
using namespace std::literals;

namespace {

std::mutex s_mtx;
std::condition_variable s_cv;
std::atomic<bool> s_tester_init_done;
std::atomic<bool> s_testee_cleanup_done;

std::atomic<long> s_testees;
std::atomic<long> s_pending_on_exits;

class testee : public event_based_actor {
public:
  testee(actor_config& cfg) : event_based_actor(cfg) {
    ++s_testees;
    ++s_pending_on_exits;
  }

  ~testee() override {
    --s_testees;
    {
      std::unique_lock guard{s_mtx};
      s_testee_cleanup_done = true;
      s_cv.notify_one();
    }
  }

  const char* name() const override {
    return "testee";
  }

  void on_exit() override {
    --s_pending_on_exits;
  }

  behavior make_behavior() override {
    return {
      [=](int x) { return x; },
    };
  }
};

template <class ExitMsgType>
behavior tester(event_based_actor* self, const actor& aut) {
  if (std::is_same_v<ExitMsgType, exit_msg>) {
    self->set_exit_handler([self](exit_msg& msg) {
      // must be still alive at this point
      if (s_testees.load() != 1)
        CAF_RAISE_ERROR(detail::format("Unexpected number of actors alive: {}",
                                       s_testees.load())
                          .c_str());
      if (msg.reason != exit_reason::user_shutdown)
        CAF_RAISE_ERROR("Unexpected exit reason");
      self->mail(ok_atom_v).schedule(self->clock().now() + 5ms).send(self);
    });
    self->link_to(aut);
    anon_mail(exit_msg{self->address(), exit_reason::user_shutdown}).send(self);
  } else {
    self->set_down_handler([self](down_msg& msg) {
      // must be still alive at this point
      if (s_testees.load() != 1)
        CAF_RAISE_ERROR(detail::format("Unexpected number of actors alive: {}",
                                       s_testees.load())
                          .c_str());
      if (msg.reason != exit_reason::user_shutdown)
        CAF_RAISE_ERROR("Unexpected exit reason");
      // testee might be still running its cleanup code in
      // another worker thread; by waiting some milliseconds, we make sure
      // testee had enough time to return control to the scheduler
      // which in turn destroys it by dropping the last remaining reference
      self->mail(ok_atom_v).schedule(self->clock().now() + 5ms).send(self);
    });
    self->monitor(aut);
    anon_mail(down_msg{self->address(), exit_reason::user_shutdown}).send(self);
  }
  anon_mail(exit_msg{self->address(), exit_reason::user_shutdown}).send(aut);
  {
    std::unique_lock<std::mutex> guard{s_mtx};
    s_tester_init_done = true;
    s_cv.notify_one();
  }
  return {
    [self](ok_atom) {
      if (s_pending_on_exits.load() != 0)
        CAF_RAISE_ERROR(
          detail::format("Unexpected number of actors pending exit: {}",
                         s_pending_on_exits.load())
            .c_str());
      self->quit();
    },
  };
}

struct fixture {
  actor_system_config cfg;
  actor_system sys;

  fixture() : sys(cfg) {
    // no op
  }

  template <spawn_options Os, class... Ts>
  actor spawn(Ts&&... xs) {
    return sys.spawn<Os>(xs...);
  }

  template <class T, spawn_options Os, class... Ts>
  actor spawn(Ts&&... xs) {
    return sys.spawn<T, Os>(xs...);
  }

  template <class ExitMsgType, spawn_options TesterOptions,
            spawn_options TesteeOptions>
  void tst() {
    // We re-use these static variables with each run.
    s_tester_init_done = false;
    s_testee_cleanup_done = false;
    // Spawn test subject and tester.
    auto tst_subject = spawn<testee, TesteeOptions>();
    auto tst_driver = spawn<TesterOptions>(tester<ExitMsgType>, tst_subject);
    if (has_detach_flag(TesterOptions)) {
      // When dealing with a detached tester we need to insert two
      // synchronization points: 1) exit_msg sent and 2) cleanup code of tester
      // done.
      { // Wait for the exit_msg from the driver.
        std::unique_lock<std::mutex> guard{s_mtx};
        while (!s_tester_init_done)
          s_cv.wait(guard);
      }
    } else {
      // When both actors are running in the scheduler we don't need any extra
      // synchronization.
      s_tester_init_done = true;
    }
  }
};

TEST("destructor call") {
  { // lifetime scope of actor system
    actor_system_config cfg;
    actor_system system{cfg};
    system.spawn<testee>();
  }
  check_eq(s_testees.load(), 0);
  check_eq(s_pending_on_exits.load(), 0);
}

WITH_FIXTURE(fixture) {

TEST("no spawn options and exit_msg") {
  tst<exit_msg, no_spawn_options, no_spawn_options>();
  {
    std::unique_lock<std::mutex> guard{s_mtx};
    while (!s_testee_cleanup_done.load())
      s_cv.wait(guard);
  }
  check_eq(s_testees.load(), 0);
  check_eq(s_pending_on_exits.load(), 0);
}

TEST("no spawn options and down_msg") {
  tst<down_msg, no_spawn_options, no_spawn_options>();
  {
    std::unique_lock<std::mutex> guard{s_mtx};
    while (!s_testee_cleanup_done.load())
      s_cv.wait(guard);
  }
  check_eq(s_testees.load(), 0);
  check_eq(s_pending_on_exits.load(), 0);
}

TEST("detached spawn options and exit_msg") {
  tst<exit_msg, detached, no_spawn_options>();
  {
    std::unique_lock<std::mutex> guard{s_mtx};
    while (!s_testee_cleanup_done.load())
      s_cv.wait(guard);
  }
  check_eq(s_testees.load(), 0);
  check_eq(s_pending_on_exits.load(), 0);
}

TEST("detached spawn options and down_msg") {
  tst<down_msg, detached, no_spawn_options>();
  {
    std::unique_lock<std::mutex> guard{s_mtx};
    while (!s_testee_cleanup_done.load())
      s_cv.wait(guard);
  }
  check_eq(s_testees.load(), 0);
  check_eq(s_pending_on_exits.load(), 0);
}

} // WITH_FIXTURE(fixture)

} // namespace

CAF_POP_WARNINGS
