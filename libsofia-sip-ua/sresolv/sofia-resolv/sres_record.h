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

#ifndef SOFIA_RESOLV_SRES_RECORD_H
/** Defined when <sofia-resolv/sres_record.h> has been included. */
#define SOFIA_RESOLV_SRES_RECORD_H
/**
 * @file sofia-resolv/sres_record.h Sofia DNS Resolver Records.
 *
 * @author Pekka Pessi <Pekka.Pessi@nokia.com>,
 *
 * @par Include Context
 * @code
 * #include <sys/types.h>
 * #include <sys/socket.h>
 * #include <netinet/in.h>
 * #include <sofia-resolv/sres_record.h>
 * @endcode
 *
 */

#include "sofia-resolv/sres_config.h"

#ifdef __cplusplus
extern "C" {
#endif
  
/** Common part of all DNS records. */
typedef struct sres_common
{
  int               r_refcount;	/**< Number of references to this record */
  char             *r_name;	/**< Domain name */
  uint16_t          r_status;	/**< Status of query (nonzero upon an error) */
  uint16_t          r_size;	/**< Size of this record */
  uint16_t          r_type;	/**< Record type (A, CNAME, A6, etc) */
  uint16_t          r_class;	/**< Record class (IN) */
  uint32_t          r_ttl;	/**< Time-to-live */
  uint16_t          r_rdlen;	/**< Length of record data */
  uint16_t          r_parsed;	/**< Nonzero if parsed */
} sres_common_t;

/** Possible values for r_status (RCODE) in #sres_common */
enum sres_status {
  SRES_OK = 0,			/**< No error condition. */
  SRES_FORMAT_ERR = 1,		/**< Server could not interpret query. */
  SRES_SERVER_ERR = 2,		/**< Server error. */
  SRES_NAME_ERR = 3,		/**< No domain name. */
  SRES_UNIMPL_ERR = 4,		/**< Not implemented. */
  SRES_AUTH_ERR = 5,		/**< Refused */

  /* Errors generated by sresolv */
  SRES_TIMEOUT_ERR = 32,	/**< Timeout occurred */
  SRES_RECORD_ERR = 33	        /**< Name has no given record type */
};

/** Start of a zone of authority record (@RFC1035). */
typedef struct sres_soa_record
{
  sres_common_t  soa_record[1];	/**< Common part of DNS records. */
  char          *soa_mname;	/**< Primary name server */
  char          *soa_rname;	/**< Person responsible for domain */
  uint32_t       soa_serial;	/**< Version number */
  uint32_t       soa_refresh;	/**< Refresh intercal */
  uint32_t       soa_retry;	/**< Interval between refres retries */
  uint32_t       soa_expire;	/**< Upper limit on zone expiration time  */
  uint32_t       soa_minimum;	/**< Minimum TTL for any record in zone */
} sres_soa_record_t;

/** Generic DNS record. */
typedef struct sres_generic
{
  sres_common_t  g_record[1];	/**< Common part of DNS records. */
  uint8_t        g_data[128];	/**< Record data */
} sres_generic_t;

/** Address record (@RFC1035). */
typedef struct sres_a_record
{
  sres_common_t  a_record[1];	/**< Common part of DNS records. */
  struct in_addr a_addr;	/**< IP4 address */
} sres_a_record_t;

/** IPv6 address used by sresolv library. 
 *
 * @sa #sres_aaaa_record, #sres_a6_record
 */
typedef struct
{
  uint8_t u6_addr[16];		/**< Array of 16 octets. */
} sres_in6_t;

/** Aggregated address record for IPv6 (@RFC2874, deprecated). */
typedef struct sres_a6_record
{
  sres_common_t  a6_record[1];	/**< Common part of DNS records. */
  uint8_t        a6_prelen;	/**< Prefix length */
  uint8_t        a6_pad[3];	/**<  */
  sres_in6_t     a6_suffix;	/**< Address suffix */
  char          *a6_prename;	/**< Prefix name */
} sres_a6_record_t;

/** Address record for IPv6 (@RFC1886). */
typedef struct sres_aaaa_record
{
  sres_common_t aaaa_record[1];	/**< Common part of DNS records. */
  sres_in6_t    aaaa_addr;	/**< IP6 address */
} sres_aaaa_record_t;

/** Canonic name record (@RFC1035). */
typedef struct sres_cname_record
{
  sres_common_t  cn_record[1];	/**< Common part of DNS records. */
  char          *cn_cname;	/**<  */
} sres_cname_record_t;

/** Pointer record (@RFC1035). */
typedef struct sres_ptr_record
{
  sres_common_t  ptr_record[1];	/**< Common part of DNS records. */
  char          *ptr_domain;	/**< Domain */
} sres_ptr_record_t;

/** Service location record (@RFC2782). */
typedef struct sres_srv_record
{
  sres_common_t  srv_record[1];	/**< Common part of DNS records. */
  uint16_t       srv_priority;	/**< Priority */
  uint16_t       srv_weight;	/**< Weight */
  uint16_t       srv_port;	/**< Service port on the target host. */
  uint16_t       srv_pad;
  char          *srv_target;	/**< Domain name of the target host. */
} sres_srv_record_t;

/** Naming authority pointer record (@RFC2915). */
typedef struct sres_naptr_record
{
  sres_common_t  na_record[1];	/**< Common part of DNS records. */
  uint16_t       na_order;	/**< Processing order for NAPTR records. */
  uint16_t       na_prefer;	/**< Preference */
  char          *na_flags;	/**< Flags for interpretation and rewriting */
  char          *na_services;	/**< Services available. */
  char          *na_regexp;	/**< Substitution expression. */
  char          *na_replace;	/**< Replacement. */
} sres_naptr_record_t;


#ifndef SRES_RECORD_T
#define SRES_RECORD_T
/** Type representing any DNS record. */
typedef union sres_record           sres_record_t;
#endif

/** Union of different DNS records */
union sres_record
{
  sres_common_t       sr_record[1];	/**< Common part of all DNS records */
  sres_generic_t      sr_generic[1];	/**< Generic (unparsed) DNS record */
  sres_soa_record_t   sr_soa[1];	/**< SOA (start-of-authority) record */
  sres_a_record_t     sr_a[1];		/**< A (address) record */
  sres_cname_record_t sr_cname[1];	/**< CNAME (canonic name) record */
  sres_ptr_record_t   sr_ptr[1];	/**< PTR (pointer) record */
  sres_a6_record_t    sr_a6[1];		/**< A6 (IP6 address) record */
  sres_aaaa_record_t  sr_aaaa[1];	/**< AAAA (IP6 address) record */
  sres_srv_record_t   sr_srv[1];	/**< SRV record */
  sres_naptr_record_t sr_naptr[1];	/**< NAPTR record */
};

/** Protocol family classes. */
enum sres_class {
  sres_class_in = 1,		        /**< Internet (@b IN) */
  sres_class_any = 255		        /**< Any class */
};

/** Query types. */
enum sres_qtypes {
  sres_type_a = 1,	    /**< IPv4 address (#sres_a_record). */
  sres_type_ns = 2,	    /**< Authoritative server. */
  sres_type_mf = 4,	    /**< Mail forwarder. */
  sres_type_cname = 5,	    /**< Canonical name (#sres_cname_record). */
  sres_type_soa = 6,	    /**< Start of authority zone (#sres_soa_record). */
  sres_type_mb = 7,	    /**< Mailbox domain name. */
  sres_type_mg = 8,	    /**< Mail group member. */
  sres_type_mr = 9,	    /**< Mail rename name. */
  sres_type_null = 10,	    /**< Null resource record. */
  sres_type_wks = 11,	    /**< Well known service. */
  sres_type_ptr = 12,	    /**< Domain name pointer (#sres_ptr_record). */
  sres_type_hinfo = 13,	    /**< Host information. */
  sres_type_minfo = 14,	    /**< Mailbox information. */
  sres_type_mx = 15,	    /**< Mail routing information. */
  sres_type_txt = 16,	    /**< Text strings. */
  sres_type_rp = 17,	    /**< Responsible person. */
  sres_type_afsdb = 18,	    /**< AFS cell database. */
  sres_type_x25 = 19,	    /**< X_25 calling address. */
  sres_type_isdn = 20,	    /**< ISDN calling address. */
  sres_type_rt = 21,	    /**< Router. */
  sres_type_nsap = 22,	    /**< NSAP address. */
  sres_type_nsap_ptr = 23,  /**< Reverse NSAP lookup. */
  sres_type_sig = 24,	    /**< Security signature. */
  sres_type_key = 25,	    /**< Security key. */
  sres_type_px = 26,	    /**< X.400 mail mapping. */
  sres_type_gpos = 27,	    /**< ICBM record. */
  sres_type_aaaa = 28,	    /**< IPv6 Address (#sres_aaaa_record). */
  sres_type_loc = 29,	    /**< Location Information. */
  sres_type_nxt = 30,	    /**< Next domain. */
  sres_type_eid = 31,	    /**< Endpoint identifier. */
  sres_type_nimloc = 32,    /**< Nimrod Locator. */
  sres_type_srv = 33,	    /**< Server Selection (@RFC2782, 
			         #sres_srv_record). */
  sres_type_atma = 34,	    /**< ATM Address */
  sres_type_naptr = 35,	    /**< Naming Authority PoinTeR (@RFC2915, 
                                 #sres_naptr_record) */
  sres_type_kx = 36,	    /**< Key Exchange */
  sres_type_cert = 37,	    /**< Certification record */
  sres_type_a6 = 38,	    /**< IPv6 address (deprecates AAAA) */
  sres_type_dname = 39,	    /**< Non-terminal DNAME (for IPv6) */
  sres_type_sink = 40,	    /**< Kitchen sink (experimental) */
  sres_type_opt = 41,	    /**< EDNS 0 option (@RFC2671) */

  sres_qtype_tsig = 250,    /**< Transaction signature. */
  sres_qtype_ixfr = 251,    /**< Incremental zone transfer. */
  sres_qtype_axfr = 252,    /**< Transfer zone of authority. */
  sres_qtype_mailb = 253,   /**< Transfer mailbox records. */
  sres_qtype_maila = 254,   /**< Transfer mail agent records. */
  sres_qtype_any = 255	    /**< Wildcard match. */
};

/** Convert type to its name. */
SRESPUBFUN char const *sres_record_type(int type, char buffer[8]);

/** Compare two records. */
SRESPUBFUN int sres_record_compare(sres_record_t const *,
				   sres_record_t const *);

#ifdef __cplusplus
}
#endif

#endif /* SOFIA_RESOLV_SRES_CACHE_H */
