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


#ifndef _NETZ_LLC_U_H_
#define _NETZ_LLC_U_H_


#include "types.h"


/*
 * IEEE 802.2 LLC (Logical Link Control) U-format header
 */

/*
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |     DSAP      |     SSAP      |M M M|P|M M|1 1| 
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 */

#pragma pack(1)

struct s_llc_u_header
{
    byte dsap;                        /* destiantion service access point */
    byte ssap;                        /* source service access point */
    byte ctrl;                        /* control*/
};

#pragma pack(4)


#define LLC_U_HEADER_LEN sizeof(s_llc_u_header)


/*
 * Control field masks and values
 */

#define LLC_U_ID_MASK        0x03     /* ID mask */
#define   LLC_U_ID              3     /* ID value */
#define LLC_U_PF_MASK        0x10     /* P/F mask */
#define LLC_U_M_MASK         0xEC     /* M bits mask including P/F as zero */
#define   LLC_U_M_UI         0x00     /* unnumbered information */
#define   LLC_U_M_SABME      0x6C     /* set asynchronous balanced mode */
#define   LLC_U_M_DISC       0x40     /* disconnect */
#define   LLC_U_M_UA         0x60     /* unnumbered acknowledgement */
#define   LLC_U_M_DM         0x0C     /* disconnected mode */
#define   LLC_U_M_FRMR       0x84     /* frame reject */
#define   LLC_U_M_XID        0xAC     /* exchange identification */
#define   LLC_U_M_TEST       0xE0     /* test */


/*
 * Definitions common for all LLC formats
 */

#include "llc.h"


#endif /* _NETZ_LLC_U_H_ */
