// clang-format off
// DO NOT EDIT: this file is auto-generated by caf-generate-enum-strings.
// Run the target update-enum-strings if this file is out of sync.
#include "caf/config.hpp"
#include "caf/string_view.hpp"

CAF_PUSH_DEPRECATED_WARNING

#include "caf/sec.hpp"

#include <string>

namespace caf {

std::string to_string(sec x) {
  switch(x) {
    default:
      return "???";
    case sec::none:
      return "none";
    case sec::unexpected_message:
      return "unexpected_message";
    case sec::unexpected_response:
      return "unexpected_response";
    case sec::request_receiver_down:
      return "request_receiver_down";
    case sec::request_timeout:
      return "request_timeout";
    case sec::no_such_group_module:
      return "no_such_group_module";
    case sec::no_actor_published_at_port:
      return "no_actor_published_at_port";
    case sec::unexpected_actor_messaging_interface:
      return "unexpected_actor_messaging_interface";
    case sec::state_not_serializable:
      return "state_not_serializable";
    case sec::unsupported_sys_key:
      return "unsupported_sys_key";
    case sec::unsupported_sys_message:
      return "unsupported_sys_message";
    case sec::disconnect_during_handshake:
      return "disconnect_during_handshake";
    case sec::cannot_forward_to_invalid_actor:
      return "cannot_forward_to_invalid_actor";
    case sec::no_route_to_receiving_node:
      return "no_route_to_receiving_node";
    case sec::failed_to_assign_scribe_from_handle:
      return "failed_to_assign_scribe_from_handle";
    case sec::failed_to_assign_doorman_from_handle:
      return "failed_to_assign_doorman_from_handle";
    case sec::cannot_close_invalid_port:
      return "cannot_close_invalid_port";
    case sec::cannot_connect_to_node:
      return "cannot_connect_to_node";
    case sec::cannot_open_port:
      return "cannot_open_port";
    case sec::network_syscall_failed:
      return "network_syscall_failed";
    case sec::invalid_argument:
      return "invalid_argument";
    case sec::invalid_protocol_family:
      return "invalid_protocol_family";
    case sec::cannot_publish_invalid_actor:
      return "cannot_publish_invalid_actor";
    case sec::cannot_spawn_actor_from_arguments:
      return "cannot_spawn_actor_from_arguments";
    case sec::end_of_stream:
      return "end_of_stream";
    case sec::no_context:
      return "no_context";
    case sec::unknown_type:
      return "unknown_type";
    case sec::no_proxy_registry:
      return "no_proxy_registry";
    case sec::runtime_error:
      return "runtime_error";
    case sec::remote_linking_failed:
      return "remote_linking_failed";
    case sec::cannot_add_upstream:
      return "cannot_add_upstream";
    case sec::upstream_already_exists:
      return "upstream_already_exists";
    case sec::invalid_upstream:
      return "invalid_upstream";
    case sec::cannot_add_downstream:
      return "cannot_add_downstream";
    case sec::downstream_already_exists:
      return "downstream_already_exists";
    case sec::invalid_downstream:
      return "invalid_downstream";
    case sec::no_downstream_stages_defined:
      return "no_downstream_stages_defined";
    case sec::stream_init_failed:
      return "stream_init_failed";
    case sec::invalid_stream_state:
      return "invalid_stream_state";
    case sec::unhandled_stream_error:
      return "unhandled_stream_error";
    case sec::bad_function_call:
      return "bad_function_call";
    case sec::feature_disabled:
      return "feature_disabled";
    case sec::cannot_open_file:
      return "cannot_open_file";
    case sec::socket_invalid:
      return "socket_invalid";
    case sec::socket_disconnected:
      return "socket_disconnected";
    case sec::socket_operation_failed:
      return "socket_operation_failed";
    case sec::unavailable_or_would_block:
      return "unavailable_or_would_block";
    case sec::incompatible_versions:
      return "incompatible_versions";
    case sec::incompatible_application_ids:
      return "incompatible_application_ids";
    case sec::malformed_basp_message:
      return "malformed_basp_message";
    case sec::serializing_basp_payload_failed:
      return "serializing_basp_payload_failed";
    case sec::redundant_connection:
      return "redundant_connection";
    case sec::remote_lookup_failed:
      return "remote_lookup_failed";
    case sec::no_tracing_context:
      return "no_tracing_context";
    case sec::all_requests_failed:
      return "all_requests_failed";
    case sec::field_invariant_check_failed:
      return "field_invariant_check_failed";
    case sec::field_value_synchronization_failed:
      return "field_value_synchronization_failed";
    case sec::invalid_field_type:
      return "invalid_field_type";
    case sec::unsafe_type:
      return "unsafe_type";
    case sec::save_callback_failed:
      return "save_callback_failed";
    case sec::load_callback_failed:
      return "load_callback_failed";
    case sec::conversion_failed:
      return "conversion_failed";
    case sec::connection_closed:
      return "connection_closed";
    case sec::type_clash:
      return "type_clash";
    case sec::unsupported_operation:
      return "unsupported_operation";
    case sec::no_such_key:
      return "no_such_key";
    case sec::broken_promise:
      return "broken_promise";
  };
}

bool from_string(string_view in, sec& out) {
  if (in == "none") {
    out = sec::none;
    return true;
  } else if (in == "unexpected_message") {
    out = sec::unexpected_message;
    return true;
  } else if (in == "unexpected_response") {
    out = sec::unexpected_response;
    return true;
  } else if (in == "request_receiver_down") {
    out = sec::request_receiver_down;
    return true;
  } else if (in == "request_timeout") {
    out = sec::request_timeout;
    return true;
  } else if (in == "no_such_group_module") {
    out = sec::no_such_group_module;
    return true;
  } else if (in == "no_actor_published_at_port") {
    out = sec::no_actor_published_at_port;
    return true;
  } else if (in == "unexpected_actor_messaging_interface") {
    out = sec::unexpected_actor_messaging_interface;
    return true;
  } else if (in == "state_not_serializable") {
    out = sec::state_not_serializable;
    return true;
  } else if (in == "unsupported_sys_key") {
    out = sec::unsupported_sys_key;
    return true;
  } else if (in == "unsupported_sys_message") {
    out = sec::unsupported_sys_message;
    return true;
  } else if (in == "disconnect_during_handshake") {
    out = sec::disconnect_during_handshake;
    return true;
  } else if (in == "cannot_forward_to_invalid_actor") {
    out = sec::cannot_forward_to_invalid_actor;
    return true;
  } else if (in == "no_route_to_receiving_node") {
    out = sec::no_route_to_receiving_node;
    return true;
  } else if (in == "failed_to_assign_scribe_from_handle") {
    out = sec::failed_to_assign_scribe_from_handle;
    return true;
  } else if (in == "failed_to_assign_doorman_from_handle") {
    out = sec::failed_to_assign_doorman_from_handle;
    return true;
  } else if (in == "cannot_close_invalid_port") {
    out = sec::cannot_close_invalid_port;
    return true;
  } else if (in == "cannot_connect_to_node") {
    out = sec::cannot_connect_to_node;
    return true;
  } else if (in == "cannot_open_port") {
    out = sec::cannot_open_port;
    return true;
  } else if (in == "network_syscall_failed") {
    out = sec::network_syscall_failed;
    return true;
  } else if (in == "invalid_argument") {
    out = sec::invalid_argument;
    return true;
  } else if (in == "invalid_protocol_family") {
    out = sec::invalid_protocol_family;
    return true;
  } else if (in == "cannot_publish_invalid_actor") {
    out = sec::cannot_publish_invalid_actor;
    return true;
  } else if (in == "cannot_spawn_actor_from_arguments") {
    out = sec::cannot_spawn_actor_from_arguments;
    return true;
  } else if (in == "end_of_stream") {
    out = sec::end_of_stream;
    return true;
  } else if (in == "no_context") {
    out = sec::no_context;
    return true;
  } else if (in == "unknown_type") {
    out = sec::unknown_type;
    return true;
  } else if (in == "no_proxy_registry") {
    out = sec::no_proxy_registry;
    return true;
  } else if (in == "runtime_error") {
    out = sec::runtime_error;
    return true;
  } else if (in == "remote_linking_failed") {
    out = sec::remote_linking_failed;
    return true;
  } else if (in == "cannot_add_upstream") {
    out = sec::cannot_add_upstream;
    return true;
  } else if (in == "upstream_already_exists") {
    out = sec::upstream_already_exists;
    return true;
  } else if (in == "invalid_upstream") {
    out = sec::invalid_upstream;
    return true;
  } else if (in == "cannot_add_downstream") {
    out = sec::cannot_add_downstream;
    return true;
  } else if (in == "downstream_already_exists") {
    out = sec::downstream_already_exists;
    return true;
  } else if (in == "invalid_downstream") {
    out = sec::invalid_downstream;
    return true;
  } else if (in == "no_downstream_stages_defined") {
    out = sec::no_downstream_stages_defined;
    return true;
  } else if (in == "stream_init_failed") {
    out = sec::stream_init_failed;
    return true;
  } else if (in == "invalid_stream_state") {
    out = sec::invalid_stream_state;
    return true;
  } else if (in == "unhandled_stream_error") {
    out = sec::unhandled_stream_error;
    return true;
  } else if (in == "bad_function_call") {
    out = sec::bad_function_call;
    return true;
  } else if (in == "feature_disabled") {
    out = sec::feature_disabled;
    return true;
  } else if (in == "cannot_open_file") {
    out = sec::cannot_open_file;
    return true;
  } else if (in == "socket_invalid") {
    out = sec::socket_invalid;
    return true;
  } else if (in == "socket_disconnected") {
    out = sec::socket_disconnected;
    return true;
  } else if (in == "socket_operation_failed") {
    out = sec::socket_operation_failed;
    return true;
  } else if (in == "unavailable_or_would_block") {
    out = sec::unavailable_or_would_block;
    return true;
  } else if (in == "incompatible_versions") {
    out = sec::incompatible_versions;
    return true;
  } else if (in == "incompatible_application_ids") {
    out = sec::incompatible_application_ids;
    return true;
  } else if (in == "malformed_basp_message") {
    out = sec::malformed_basp_message;
    return true;
  } else if (in == "serializing_basp_payload_failed") {
    out = sec::serializing_basp_payload_failed;
    return true;
  } else if (in == "redundant_connection") {
    out = sec::redundant_connection;
    return true;
  } else if (in == "remote_lookup_failed") {
    out = sec::remote_lookup_failed;
    return true;
  } else if (in == "no_tracing_context") {
    out = sec::no_tracing_context;
    return true;
  } else if (in == "all_requests_failed") {
    out = sec::all_requests_failed;
    return true;
  } else if (in == "field_invariant_check_failed") {
    out = sec::field_invariant_check_failed;
    return true;
  } else if (in == "field_value_synchronization_failed") {
    out = sec::field_value_synchronization_failed;
    return true;
  } else if (in == "invalid_field_type") {
    out = sec::invalid_field_type;
    return true;
  } else if (in == "unsafe_type") {
    out = sec::unsafe_type;
    return true;
  } else if (in == "save_callback_failed") {
    out = sec::save_callback_failed;
    return true;
  } else if (in == "load_callback_failed") {
    out = sec::load_callback_failed;
    return true;
  } else if (in == "conversion_failed") {
    out = sec::conversion_failed;
    return true;
  } else if (in == "connection_closed") {
    out = sec::connection_closed;
    return true;
  } else if (in == "type_clash") {
    out = sec::type_clash;
    return true;
  } else if (in == "unsupported_operation") {
    out = sec::unsupported_operation;
    return true;
  } else if (in == "no_such_key") {
    out = sec::no_such_key;
    return true;
  } else if (in == "broken_promise") {
    out = sec::broken_promise;
    return true;
  } else {
    return false;
  }
}

bool from_integer(std::underlying_type_t<sec> in,
                  sec& out) {
  auto result = static_cast<sec>(in);
  switch(result) {
    default:
      return false;
    case sec::none:
    case sec::unexpected_message:
    case sec::unexpected_response:
    case sec::request_receiver_down:
    case sec::request_timeout:
    case sec::no_such_group_module:
    case sec::no_actor_published_at_port:
    case sec::unexpected_actor_messaging_interface:
    case sec::state_not_serializable:
    case sec::unsupported_sys_key:
    case sec::unsupported_sys_message:
    case sec::disconnect_during_handshake:
    case sec::cannot_forward_to_invalid_actor:
    case sec::no_route_to_receiving_node:
    case sec::failed_to_assign_scribe_from_handle:
    case sec::failed_to_assign_doorman_from_handle:
    case sec::cannot_close_invalid_port:
    case sec::cannot_connect_to_node:
    case sec::cannot_open_port:
    case sec::network_syscall_failed:
    case sec::invalid_argument:
    case sec::invalid_protocol_family:
    case sec::cannot_publish_invalid_actor:
    case sec::cannot_spawn_actor_from_arguments:
    case sec::end_of_stream:
    case sec::no_context:
    case sec::unknown_type:
    case sec::no_proxy_registry:
    case sec::runtime_error:
    case sec::remote_linking_failed:
    case sec::cannot_add_upstream:
    case sec::upstream_already_exists:
    case sec::invalid_upstream:
    case sec::cannot_add_downstream:
    case sec::downstream_already_exists:
    case sec::invalid_downstream:
    case sec::no_downstream_stages_defined:
    case sec::stream_init_failed:
    case sec::invalid_stream_state:
    case sec::unhandled_stream_error:
    case sec::bad_function_call:
    case sec::feature_disabled:
    case sec::cannot_open_file:
    case sec::socket_invalid:
    case sec::socket_disconnected:
    case sec::socket_operation_failed:
    case sec::unavailable_or_would_block:
    case sec::incompatible_versions:
    case sec::incompatible_application_ids:
    case sec::malformed_basp_message:
    case sec::serializing_basp_payload_failed:
    case sec::redundant_connection:
    case sec::remote_lookup_failed:
    case sec::no_tracing_context:
    case sec::all_requests_failed:
    case sec::field_invariant_check_failed:
    case sec::field_value_synchronization_failed:
    case sec::invalid_field_type:
    case sec::unsafe_type:
    case sec::save_callback_failed:
    case sec::load_callback_failed:
    case sec::conversion_failed:
    case sec::connection_closed:
    case sec::type_clash:
    case sec::unsupported_operation:
    case sec::no_such_key:
    case sec::broken_promise:
      out = result;
      return true;
  };
}

} // namespace caf

CAF_POP_WARNINGS
