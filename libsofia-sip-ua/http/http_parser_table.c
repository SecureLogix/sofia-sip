/*
 * This file is part of the Sofia-SIP package
 *
 * Copyright (C) 2005 Nokia Corporation.
 *
 * Contact: Pekka Pessi <pekka.pessi@nokia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

/**@internal
 * @CFILE http_parser_table.c 
 * @brief HTTP parser table
 *
 * This file is automatically generated from <http.h> by msg_parser.awk.
 *
 * @author Pekka Pessi <Pekka.Pessi@nokia.com>
 *
 * @date Created: Tue Oct  1 20:37:52 2002 ppessi
 */

#include "config.h"

#include <stddef.h>
#include <string.h>

/* Avoid casting http_t to msg_pub_t and http_header_t to msg_header_t  */
#define MSG_PUB_T struct http_s
#define MSG_HDR_T union http_header_u

#include <sofia-sip/http_parser.h>
#include <sofia-sip/msg_mclass.h>

#define HTTP_PARSER_FLAGS (MSG_FLG_CHUNKING)



#define msg_offsetof(s, f) ((unsigned short)offsetof(s ,f))


msg_mclass_t const http_mclass[1] = 
{{
# if defined (HTTP_HCLASS)
  HTTP_HCLASS,
#else
  {{ 0 }},
#endif
  HTTP_VERSION_CURRENT,
  HTTP_PROTOCOL_TAG,
#if defined (HTTP_PARSER_FLAGS)
  HTTP_PARSER_FLAGS,
#else
  0,
#endif
  sizeof (http_t),
  http_extract_body,
  {{ http_request_class, msg_offsetof(http_t, http_request) }},
  {{ http_status_class, msg_offsetof(http_t, http_status) }},
  {{ http_separator_class, msg_offsetof(http_t, http_separator) }},
  {{ http_payload_class, msg_offsetof(http_t, http_payload) }},
  {{ http_unknown_class, msg_offsetof(http_t, http_unknown) }},
  {{ http_error_class, msg_offsetof(http_t, http_error) }},
  {{ NULL, 0 }},
  NULL, 
  127, 
  52,
  {
    { http_proxy_authenticate_class, msg_offsetof(http_t, http_proxy_authenticate) },
    { http_from_class, msg_offsetof(http_t, http_from) },
    { http_upgrade_class, msg_offsetof(http_t, http_upgrade) },
    { NULL, 0 },
    { NULL, 0 },
    { http_content_language_class, msg_offsetof(http_t, http_content_language) },
    { NULL, 0 },
    { http_accept_class, msg_offsetof(http_t, http_accept) },
    { http_if_unmodified_since_class, msg_offsetof(http_t, http_if_unmodified_since) },
    { http_referer_class, msg_offsetof(http_t, http_referer) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_via_class, msg_offsetof(http_t, http_via) },
    { http_user_agent_class, msg_offsetof(http_t, http_user_agent) },
    { NULL, 0 },
    { http_last_modified_class, msg_offsetof(http_t, http_last_modified) },
    { http_accept_charset_class, msg_offsetof(http_t, http_accept_charset) },
    { http_authentication_info_class, msg_offsetof(http_t, http_authentication_info) },
    { http_content_length_class, msg_offsetof(http_t, http_content_length) },
    { NULL, 0 },
    { http_content_location_class, msg_offsetof(http_t, http_content_location) },
    { http_mime_version_class, msg_offsetof(http_t, http_mime_version) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_etag_class, msg_offsetof(http_t, http_etag) },
    { http_expect_class, msg_offsetof(http_t, http_expect) },
    { http_proxy_authorization_class, msg_offsetof(http_t, http_proxy_authorization) },
    { NULL, 0 },
    { NULL, 0 },
    { http_date_class, msg_offsetof(http_t, http_date) },
    { NULL, 0 },
    { http_content_md5_class, msg_offsetof(http_t, http_content_md5) },
    { http_accept_ranges_class, msg_offsetof(http_t, http_accept_ranges) },
    { http_if_match_class, msg_offsetof(http_t, http_if_match) },
    { http_content_type_class, msg_offsetof(http_t, http_content_type) },
    { NULL, 0 },
    { NULL, 0 },
    { http_accept_language_class, msg_offsetof(http_t, http_accept_language) },
    { NULL, 0 },
    { NULL, 0 },
    { http_vary_class, msg_offsetof(http_t, http_vary) },
    { NULL, 0 },
    { http_max_forwards_class, msg_offsetof(http_t, http_max_forwards) },
    { http_age_class, msg_offsetof(http_t, http_age) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_connection_class, msg_offsetof(http_t, http_connection) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_warning_class, msg_offsetof(http_t, http_warning) },
    { NULL, 0 },
    { http_host_class, msg_offsetof(http_t, http_host) },
    { http_allow_class, msg_offsetof(http_t, http_allow) },
    { NULL, 0 },
    { http_content_encoding_class, msg_offsetof(http_t, http_content_encoding) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_authorization_class, msg_offsetof(http_t, http_authorization) },
    { http_content_range_class, msg_offsetof(http_t, http_content_range) },
    { NULL, 0 },
    { http_cookie_class, msg_offsetof(http_t, http_cookie) },
    { NULL, 0 },
    { NULL, 0 },
    { http_server_class, msg_offsetof(http_t, http_server) },
    { NULL, 0 },
    { http_if_range_class, msg_offsetof(http_t, http_if_range) },
    { NULL, 0 },
    { http_te_class, msg_offsetof(http_t, http_te) },
    { NULL, 0 },
    { NULL, 0 },
    { http_www_authenticate_class, msg_offsetof(http_t, http_www_authenticate) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_trailer_class, msg_offsetof(http_t, http_trailer) },
    { http_if_none_match_class, msg_offsetof(http_t, http_if_none_match) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_set_cookie_class, msg_offsetof(http_t, http_set_cookie) },
    { NULL, 0 },
    { http_range_class, msg_offsetof(http_t, http_range) },
    { http_expires_class, msg_offsetof(http_t, http_expires) },
    { http_if_modified_since_class, msg_offsetof(http_t, http_if_modified_since) },
    { NULL, 0 },
    { NULL, 0 },
    { http_transfer_encoding_class, msg_offsetof(http_t, http_transfer_encoding) },
    { NULL, 0 },
    { NULL, 0 },
    { http_proxy_connection_class, msg_offsetof(http_t, http_proxy_connection) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_location_class, msg_offsetof(http_t, http_location) },
    { http_cache_control_class, msg_offsetof(http_t, http_cache_control) },
    { http_accept_encoding_class, msg_offsetof(http_t, http_accept_encoding) },
    { http_pragma_class, msg_offsetof(http_t, http_pragma) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 },
    { http_retry_after_class, msg_offsetof(http_t, http_retry_after) },
    { NULL, 0 },
    { NULL, 0 },
    { NULL, 0 }
  }
}};

