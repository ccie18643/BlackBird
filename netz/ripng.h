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


#ifndef _NETZ_RIPNG_H_
#define _NETZ_RIPNG_H_


#include "types.h"

#define IP6_ADDR_LEN 16


/*
 * Structure of an RIPng header ()
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |    Command    |    Version    |              Pad              |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 *
 */

struct s_ripng_header {
	byte cmd;		/* command */
	byte ver;		/* version */
	word pad;		/* not used, must be set to 0 */
};

#define RIPNG_HEADER_LEN sizeof(s_ripng_header)


/*
 * RIPng commands
 */

#define RIPNG_CMD_REQUEST    1
#define RIPNG_CMD_RESPONSE   2


/*
 * Structure of RIPng route entry ()
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |                                                               |
 * +                                                               + 
 * |                                                               |
 * +                         IPv6 Prefix                           +   
 * |                                                               |      
 * +                                                               +   
 * |                                                               |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 * |           Route tag         |  Prefix length  |    Metric     |      
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+    
 *
 */

struct s_ripng_route_entry {
	byte prefix[IP6_ADDR_LEN];    /* IPv6 Prefix */
	word tag;	              /* route tag */
	byte prefix_len;	      /* prefix length */
	byte metric;	 	      /* metric */
};

#define RIPNG_ENTRY_LEN sizeof(s_ripng_route_entry)



/*
 * Structure of RIPng next hop entry ()
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |                                                               |
 * +                                                               +
 * |                                                               |
 * +                          Next hop                             +
 * |                                                               |
 * +                                                               +
 * |                                                               |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |             0x0000          |       0x00      |      0xFF     |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * 
 */
 
struct s_ripng_next_hop_entry {
        byte next_hop[IP6_ADDR_LEN];   /* IPv6 Prefix */
        word pad1;                     /* always set to 0x0000 */
        byte pad2;                     /* always set to 0x00 */
        byte metric;                   /* always set to 0xFF */
};


#define RIPNG_NEXT_HOP_ENTRY_ID 0xFF

#endif /* _NETZ_RIPNG_H_ */

