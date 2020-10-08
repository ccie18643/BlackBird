/*
 * Copyright (c) 2001 - 2003
 *      Sebastian Majewski. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Sebastian Majewski
 *      and his contributors.
 * 4. Neither the name of Sebastian Majewski nor the names of his contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#ifndef _NETZ_RIP_H_
#define _NETZ_RIP_H_


#include "types.h"

/*
 * Structure of an RIP/RIPv2 header (RFC 2453)
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |    Command    |    Version    |              Pad              |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 *
 */

struct s_rip_header {
	byte cmd;		/* command */
	byte ver;		/* version */
	word pad;		/* not used, must be set to 0 */
};

#define RIP_HEADER_LEN sizeof(s_rip_header)


/*
 * RIP commands
 */

#define RIP_CMD_REQUEST    1
#define RIP_CMD_RESPONSE   2


/*
 * Structure of an RIP/RIPv2 entry (RFC 2453)
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |   Address Family Identifier   |           Route Tag           |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                          IP Address                           |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                          Subnet Mask                          |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                           Next Hop                            |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                            Metric                             |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 *
 */

struct s_rip_entry {
	word afi;		/* address family identifier */
	word tag;		/* route tag (RIPv2) */
	dword ip;		/* ip address */
	dword mask;		/* subnet mask (RIPv2) */
	dword nexthop;		/* next hop (RIPv2) */
	dword metric;		/* metric */
};

#define RIP_ENTRY_LEN sizeof(s_rip_entry)


/*
 * Structure of an RIPv2 authentication entry (RFC 2453)
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |            0xFFFF             |       Authentication Type     |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                                                               |      
 * |                      Authentication Key                       |      
 * |                                                               |      
 * |                                                               |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 *
 */

struct s_rip_authentry {
	word id;		/* entry id, must be set to 0xFFFF */
	word type;		/* authentication type */

        union {
	    byte key[16];	/* key for simple authentication */

            struct {            /* fields for md5 authentication */
                word len;       /* RIPv2 packet length */
                byte keyid;     /* key ID */
                byte adlen;     /* authentication data length */
                dword seq;      /* sequence number */
                dword pad[2]; 
            } md5;
        };
};

#define RIP_AUTHENTRY_LEN sizeof(s_rip_authentry)

#define RIP_AUTHENTRY_ID  0xFFFF


/*
 * RIP authentication types
 */

#define RIP_AUTHTYPE_SIMPLE  2
#define RIP_AUTHTYPE_MD5     3


/*
 * Structure of an RIPv2 MD5 authentication entry (RFC 2453)
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |            0xFFFF             |            0x0001             |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                                                               |
 * |                     MD5 Authentication Key                    |
 * |                                                               |
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 */

struct s_rip_md5entry{
	word id1;
	word id2;
        byte key[16];
};

#define RIP_MD5ENTRY_LEN sizeof(s_rip_md5entry)

#define RIP_MD5ENTRY_ID1 0xFFFF
#define RIP_MD5ENTRY_ID2 0x0001


#endif /* _NETZ_RIP_H_ */

