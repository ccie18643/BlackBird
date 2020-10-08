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


#ifndef _NETZ_IGMP_H_
#define _NETZ_IGMP_H_


#include "types.h"


/*
 * IGMP packet format.
 */

struct s_igmp_header
{
    byte  type;		/* version & type of IGMP message  */
    byte  code;		/* code for routing sub-messages   */
    word  cksum;	/* IP-style checksum               */
    dword group;	/* group address being reported    */
};


#define IGMP_HEADER_LEN sizeof(s_igmp_header)


#define	IGMP_HOST_MEMBERSHIP_QUERY	0x11  /* membership query      */
#define	IGMP_V1_HOST_MEMBERSHIP_REPORT	0x12  /* v1 membership report  */
#define	IGMP_DVMRP			0x13  /* DVMRP routing message */
#define	IGMP_PIM			0x14  /* PIM routing message   */
#define	IGMP_V2_HOST_MEMBERSHIP_REPORT	0x16  /* v2 membership report  */
#define	IGMP_HOST_LEAVE_MESSAGE		0x17  /* leave-group message   */
#define	IGMP_MTRACE_REPLY		0x1e  /* traceroute reply      */
#define	IGMP_MTRACE_QUERY		0x1f  /* traceroute query      */


#define	IGMP_DELAYING_MEMBER	1
#define	IGMP_IDLE_MEMBER	2
#define	IGMP_LAZY_MEMBER	3
#define	IGMP_SLEEPING_MEMBER	4
#define	IGMP_AWAKENING_MEMBER	5


#endif /* _NETZ_IGMP_H_ */
