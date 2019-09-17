/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright 2011-2018 Dominik Charousset                                     *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENSE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#pragma once

#include <array>
#include <functional>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <utility>

#include "caf/fwd.hpp"
#include "caf/rtti_pair.hpp"
#include "caf/type_erased_value.hpp"
#include "caf/type_nr.hpp"

namespace caf {

class uniform_type_info_map {
public:
  // -- friends ----------------------------------------------------------------

  friend class actor_system;

  // -- member types -----------------------------------------------------------

  using value_factory = std::function<type_erased_value_ptr()>;

  using value_factories_by_name = std::unordered_map<std::string,
                                                     value_factory>;

  using value_factory_kvp = std::pair<std::string, value_factory>;

  // -- factories --------------------------------------------------------------

  type_erased_value_ptr make_value(uint16_t nr) const;

  type_erased_value_ptr make_value(const std::string& x) const;

  type_erased_value_ptr make_value(const std::type_info& x) const;

  // -- properties -------------------------------------------------------------

  /// Returns the portable name for given type information or
  /// `default_type_name()` if no mapping was found.
  const std::string& portable_name(uint16_t nr, const std::type_info* ti) const;

  /// Returns the portable name for given type information or
  /// `default_type_name()` if no mapping was found.
  const std::string& portable_name(rtti_pair x) const {
    return portable_name(x.first, x.second);
  }

  /// Returns the portable name for `T` or `default_type_name()` if no mapping
  /// was found.
  template <class T>
  const std::string& portable_name() const {
    return portable_name(make_rtti_pair<T>());
  }

  /// Returns the enclosing actor system.
  actor_system& system() const {
    return system_;
  }

  /// Returns the default type name for unknown types.
  const std::string& default_type_name() const {
    return default_type_name_;
  }

private:
  // -- constructors, destructors, and assignment operators --------------------

  uniform_type_info_map(actor_system& sys);

  // -- member variables -------------------------------------------------------

  /// Reference to the parent system.
  actor_system& system_;

  /// Value factories for builtin types.
  std::array<value_factory_kvp, type_nrs - 1> builtin_;

  /// Names of builtin types.
  std::array<std::string, type_nrs - 1> builtin_names_;

  /// Displayed name for unknown types.
  std::string default_type_name_;
};

} // namespace caf
