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


#ifndef _NETZ_ETHER_VLAN_H_
#define _NETZ_ETHER_VLAN_H_


#include "types.h"


#define ETHER_VLAN_ADDR_LEN 6


/*
 * ETHERNET frame headder + IEEE 802.1Q VLAN tagging 
 */

struct s_ether_vlan_header
{
    byte dst[ETHER_VLAN_ADDR_LEN];	/* destination host address */
    byte src[ETHER_VLAN_ADDR_LEN];	/* source host address */
    word tpid;				/* tag protocol identifier */
    word tci;				/* tag control information */
    word type;			        /* type of carried protocol */
};


#define ETHER_VLAN_HEADER_LEN sizeof(s_ether_vlan_header)


/*
 * Etherenet Vlan tpid field value
 */

#define ETHER_VLAN_TPID		     0x8100    /* vlan tpid value */


/*
 * Masks for tci field
 */

#define ETHER_VLAN_TCI_PRIORITY_MASK 0xE000	/* mask of priority bits */
#define ETHER_VLAN_TCI_VID_MASK      0x0FFF	/* mask of VLAN identifier */ 


/*
 * Definitions of protocols (type)
 */
 
#include "ether_type.h"			/* definitions and print function */


#endif /* _NETZ_ETHER_VLAN_H_ */

