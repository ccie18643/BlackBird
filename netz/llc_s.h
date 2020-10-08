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


#ifndef _NETZ_LLC_S_H_
#define _NETZ_LLC_S_H_


#include "types.h"


/*
 * IEEE 802.2 LLC (Logical Link Control) S-format header
 */

/*
 *
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |     DSAP      |     SSAP      |X X X X|S S|0 1|     N(R)    |P|
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 */

struct s_llc_s_header
{
    byte dsap;                        /* destiantion service access point */
    byte ssap;	                      /* source service access point */
    word ctrl;                        /* control*/
};


#define LLC_S_HEADER_LEN sizeof(s_llc_s_header)


/*
 * Control field masks and values
 */

#define LLC_S_ID_MASK        0x0300   /* ID mask */
#define   LLC_S_ID                1   /* ID value */
#define LLC_S_S_MASK         0x0C00   /* S mask */
#define   LLC_S_S_RR         0x00     /* Receive Ready */
#define   LLC_S_S_RNR        0x80     /* Receive Not Ready */
#define   LLC_S_S_REJ        0x40     /* Reject */
#define LLC_S_PF_MASK        0x0001   /* P/F mask */
#define LLC_S_NR_MASK        0x00FE   /* N(R) mask  */


/*
 * Definitions common for all LLC formats
 */

#include "llc.h"

#endif /* _NETZ_LLC_S_H_ */
