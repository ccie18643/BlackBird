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


#include "spx_support.h"


c_spx_header::c_spx_header(byte* spx_header)
{
    header = (s_spx_header*)spx_header;
}


c_spx_header::c_spx_header(s_spx_header* spx_header)
{
    header = spx_header;
}


byte c_spx_header::get_ccflags()
{
    return ntoh(header->ccflags);
}


void c_spx_header::set_ccflags(byte ccflags)
{
    header->ccflags = hton(ccflags);
}


byte c_spx_header::get_ccflag_eom()
{
    return bits(get_ccflags(), SPX_CCFLAGS_EOM);
}
 
 
void c_spx_header::set_ccflag_eom(byte flag)
{
    header->ccflags = hton(bits(ntoh(header->ccflags),
        SPX_CCFLAGS_EOM, flag));
}


byte c_spx_header::get_ccflag_ack()
{
    return bits(get_ccflags(), SPX_CCFLAGS_ACK);
}


void c_spx_header::set_ccflag_ack(byte flag)
{
    header->ccflags = hton(bits(ntoh(header->ccflags),
        SPX_CCFLAGS_ACK, flag));
}


byte c_spx_header::get_ccflag_sys()
{
    return bits(get_ccflags(), SPX_CCFLAGS_SYS);
}


void c_spx_header::set_ccflag_sys(byte flag)
{
    header->ccflags = hton(bits(ntoh(header->ccflags),
        SPX_CCFLAGS_SYS, flag));
}


byte c_spx_header::get_dtype()
{
    return ntoh(header->dtype);
}


void c_spx_header::set_dtype(byte dtype)
{
    header->dtype = hton(dtype);
}


word c_spx_header::get_srcid()
{
    return ntoh(header->srcid);
}


void c_spx_header::set_srcid(word srcid)
{
    header->srcid = hton(srcid);
}


word c_spx_header::get_dstid()
{
    return ntoh(header->dstid);
}


void c_spx_header::set_dstid(word dstid)
{
    header->dstid = hton(dstid);
}


word c_spx_header::get_seq()
{
    return ntoh(header->seq);
}


void c_spx_header::set_seq(word seq)
{
    header->seq = hton(seq);
}


word c_spx_header::get_ack()
{
    return ntoh(header->ack);
}


void c_spx_header::set_ack(word ack)
{
    header->ack = hton(ack);
}


word c_spx_header::get_alloc()
{
    return ntoh(header->alloc);
}


void c_spx_header::set_alloc(word alloc)
{
    header->alloc = hton(alloc);
}

