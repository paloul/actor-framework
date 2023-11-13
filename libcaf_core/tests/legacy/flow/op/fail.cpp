// This file is part of CAF, the C++ Actor Framework. See the file LICENSE in
// the main distribution directory for license terms and copyright or visit
// https://github.com/actor-framework/actor-framework/blob/master/LICENSE.

#define CAF_SUITE flow.op.fail

#include "caf/flow/observable_builder.hpp"
#include "caf/flow/scoped_coordinator.hpp"

#include "core-test.hpp"

using namespace caf;

namespace {

struct fixture : test_coordinator_fixture<> {
  flow::scoped_coordinator_ptr ctx = flow::make_scoped_coordinator();
};

} // namespace

BEGIN_FIXTURE_SCOPE(fixture)

SCENARIO("the fail operator immediately calls on_error on any subscriber") {
  GIVEN("a fail<int32> operator") {
    WHEN("an observer subscribes") {
      THEN("the observer receives on_error") {
        using snk_t = flow::passive_observer<int32_t>;
        auto snk = ctx->add_child(std::in_place_type<snk_t>);
        auto uut = ctx->make_observable().fail<int32_t>(sec::runtime_error);
        uut.subscribe(snk->as_observer());
        ctx->run();
        CHECK(!snk->sub);
        CHECK_EQ(snk->state, flow::observer_state::aborted);
        CHECK(snk->buf.empty());
      }
    }
  }
}

END_FIXTURE_SCOPE()
