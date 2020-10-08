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


#include "ah_support.h"
#include "support.h"


c_ah_header::c_ah_header(byte* ah_header)
{
    header = (s_ah_header*)ah_header;
}


c_ah_header::c_ah_header(s_ah_header* ah_header)
{
    header = ah_header;
}


byte c_ah_header::get_proto()
{
    return ntoh(header->proto);
}


void c_ah_header::set_proto(byte proto)
{
    header->proto = hton(proto);
}


byte c_ah_header::get_hlen()
{
    return (ntoh(header->hlen) + 2) << 2;
}


void c_ah_header::set_hlen(byte hlen)
{
    header->hlen = hton(byte((hlen >> 2) - 2));
}


word c_ah_header::get_reserved()
{
    return ntoh(header->reserved);
}


void c_ah_header::set_reserved(word reserved)
{
    header->reserved = hton(reserved);
}


dword c_ah_header::get_spi()
{
    return ntoh(header->spi);
}


void c_ah_header::set_spi(dword spi)
{
    header->spi = hton(spi);    
}


dword c_ah_header::get_seq()
{
    return ntoh(header->seq);
}


void c_ah_header::set_seq(dword seq)
{
    header->seq = hton(seq);
}

