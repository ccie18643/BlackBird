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

#ifndef _NETZ_ARP_H_
#define _NETZ_ARP_H_


#include "types.h"


struct	s_arp_header
{
	word  hrtype;		/* type of hardware address */
	word  prtype;		/* type of protocol address */
	byte  hrlen;		/* length of hardware address */
	byte  prlen;		/* length of protocol address */
	word  operation;	/* operation type */

/*
 * The remaining fields are variable in size,
 * according to the sizes above.
 */

#ifdef COMMENT_ONLY
	byte  sha[hrlen];	/* sender hardware address */
	byte  spa[prlen];	/* sender protocol address */
	byte  tha[hrlen];	/* target hardware address */
	byte  tpa[prlen];	/* target protocol address */
#endif
};

#define ARP_HEADER_LEN sizeof(s_arp_header);


/*
 * Definitions of hardware type addresses and lenghts (hraddr and hrlen)
 */

#include "hr_type.h"		/* definitions */


/*
 * Definitions of protocol type addresses (prtype)
 */
 
#include "ether_type.h"		/* definitions */

#define ARP_PRTYPE_IP          ETHER_TYPE_IP
#define ARP_PRTYPE_IP6         ETHER_TYPE_IP6


/*
 * Definitions of protocol type address lengths (prlen)
 */

#define ARP_PRLEN_IP           4
#define ARP_PRLEN_IP6         16
 

/*
 * Operation (operation)
 */

#define	ARP_OP_REQUEST	    1	/* request to resolve address */
#define	ARP_OP_REPLY	    2	/* response to previous request */
#define	ARP_OP_REVREQUEST   3	/* request protocol address given hardware */
#define	ARP_OP_REVREPLY	    4	/* response giving protocol address */
#define	ARP_OP_INVREQUEST   8 	/* request to identify peer */
#define	ARP_OP_INVREPLY	    9	/* response identifying peer */


#endif /* _NETZ_ARP_H_ */
