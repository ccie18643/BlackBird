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


#include "llc_u_support.h"
#include "support.h"


c_llc_u_header::c_llc_u_header(byte* llc_u_header)
{
    header = (s_llc_u_header*)llc_u_header;
}


c_llc_u_header::c_llc_u_header(s_llc_u_header* llc_u_header)
{
    header = llc_u_header;
}


byte c_llc_u_header::get_dsap()
{
    return ntoh(header->dsap);
}


void c_llc_u_header::set_dsap(byte dsap)
{
    header->dsap = hton(dsap);
}


byte c_llc_u_header::get_dsap_ig()
{
    return bits(ntoh(header->dsap), LLC_DSAP_IG_MASK);
}


void c_llc_u_header::set_dsap_ig(byte ig)
{
    header->dsap = hton(bits(ntoh(header->dsap), LLC_DSAP_IG_MASK, ig));
}


byte c_llc_u_header::get_dsap_addr()
{
    return bits(ntoh(header->dsap), LLC_DSAP_ADDR_MASK);
}


void c_llc_u_header::set_dsap_addr(byte addr)
{
    header->dsap = hton(bits(ntoh(header->dsap), LLC_DSAP_ADDR_MASK, addr));
}

byte c_llc_u_header::get_ssap()
{
    return ntoh(header->ssap);
}


void c_llc_u_header::set_ssap(byte ssap)
{
    header->ssap = hton(ssap);
}


byte c_llc_u_header::get_ssap_cr()
{
    return bits(ntoh(header->ssap), LLC_SSAP_CR_MASK);
}


void c_llc_u_header::set_ssap_cr(byte cr)
{
    header->dsap = hton(bits(ntoh(header->ssap), LLC_SSAP_CR_MASK, cr));
}


byte c_llc_u_header::get_ssap_addr()
{
    return bits(ntoh(header->ssap), LLC_SSAP_ADDR_MASK);
}


void c_llc_u_header::set_ssap_addr(byte addr)
{
    header->dsap = hton(bits(ntoh(header->ssap), LLC_SSAP_ADDR_MASK, addr));
}


byte c_llc_u_header::get_ctrl()
{
    return ntoh(header->ctrl);
}


void c_llc_u_header::set_ctrl(byte ctrl)
{
    header->ctrl = hton(ctrl);
}


byte c_llc_u_header::get_ctrl_m()
{
    return bits(header->ctrl, LLC_U_M_MASK);
}


void c_llc_u_header::set_ctrl_m(byte m)
{
    header->ctrl = bits(header->ctrl, LLC_U_M_MASK, m);
}


byte c_llc_u_header::get_ctrl_pf()
{
    return bits(header->ctrl, LLC_U_PF_MASK);
}


void c_llc_u_header::set_ctrl_pf(byte pf) 
{
    header->ctrl = bits(header->ctrl, LLC_U_PF_MASK, pf);
}

