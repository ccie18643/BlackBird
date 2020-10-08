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


#ifndef _NETZ_LLC_U_SUPPORT_H_
#define _NETZ_LLC_U_SUPPORT_H_


#include "llc_u.h"


class c_llc_u_header
{
protected:
    s_llc_u_header* header;

public:
    c_llc_u_header(byte*);
    c_llc_u_header(s_llc_u_header*);

    byte get_dsap();
    byte get_dsap_ig();
    byte get_dsap_addr();
    byte get_ssap();
    byte get_ssap_cr();
    byte get_ssap_addr();
    byte get_ctrl();
    byte get_ctrl_m();
    byte get_ctrl_pf();

    void set_dsap(byte);
    void set_dsap_ig(byte);
    void set_dsap_addr(byte);
    void set_ssap(byte);
    void set_ssap_cr(byte);
    void set_ssap_addr(byte);
    void set_ctrl(byte = 0x03);
    void set_ctrl_m(byte);
    void set_ctrl_pf(byte);
};


#endif /* _NETZ_LLC_U_SUPPORT_H_ */
