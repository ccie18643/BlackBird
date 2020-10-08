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


#ifndef _NETZ_LLC_H_
#define _NETZ_LLC_H_


/*
 * LLC DSAP field bit masks
 */

#define LLC_DSAP_ADDR_MASK   0xFC     /* DSAP main address part mask */
#define LLC_DSAP_ISO_MASK    0x02     /* DSAP ISO bit mask */
#define LLC_DSAP_IG_MASK     0x01     /* individual/group bit mask */


/*
 * LLC SSAP fiels bit masks
 */

#define LLC_SSAP_CR_MASK     0x01     /* command/request bit mask */
#define LLC_SSAP_ADDR_MASK   0xFE     /* SSAP main address part mask */


/*
 * SAP values
 */

#define LLC_SAP_NLSAP         0x00    /* Null LSAP */
#define LLC_SAP_ILSM          0x02    /* Individual LLC Sublayer Mgt */ 
#define LLC_SAP_GLSM          0x03    /* Group LLC Sublayer Mgt */ 
#define LLC_SAP_SNAPC         0x04    /* SNA Path Control */
#define LLC_SAP_DODIP         0x06    /* DoD IP */
#define LLC_SAP_PLAN_0E       0x0E    /* PROWAY-LAN */
#define LLC_SAP_EIA           0x4E    /* EIA-RS 511 */
#define LLC_SAP_ISIIP         0x5E    /* ISI IP */
#define LLC_SAP_3COM          0x80    /* 3Com */
#define LLC_SAP_PLAN_8E       0x8E    /* PROWAY-LAN */
#define LLC_SAP_SNAP          0xAA    /* SNAP */
#define LLC_SAP_BC            0xBC    /* Banyan */
#define LLC_SAP_NOVELL        0xE0    /* Novell */
#define LLC_SAP_NETBEUI       0xF0    /* NetBEUI */
#define LLC_SAP_LANMAN        0xF4    /* Lan Manager */
#define LLC_SAP_CLNS          0xFE    /* ISO CLNS IS 8473 */
#define LLC_SAP_GLOBAL        0xFF    /* Global DSAP */ 


#endif /* _NETZ_LLC_H_ */
