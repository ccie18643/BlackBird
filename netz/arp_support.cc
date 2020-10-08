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


#ifdef OS_AIX
    #include <memory.h>
#endif

#ifdef OS_OPENBSD
    #include <memory.h>
#endif

#ifdef OS_LINUX
    #include <string.h>
#endif


#include "arp_support.h"
#include "support.h"


c_arp_header::c_arp_header(byte* arp_header)
{
    header = (s_arp_header*)arp_header;

    sha = arp_header + ARP_HEADER_LEN;
    spa = sha + get_hrlen();
    tha = spa + get_prlen();
    tpa = tha + get_hrlen();
}


c_arp_header::c_arp_header(s_arp_header* arp_header)
{
    header = arp_header;

    sha = ((byte*)arp_header) + ARP_HEADER_LEN;
    spa = sha + get_hrlen();
    tha = spa + get_prlen();
    tpa = tha + get_hrlen();
}


word c_arp_header::get_hrtype()
{
    return ntoh(header->hrtype);
}


void c_arp_header::set_hrtype(word hrtype)
{
    header->hrtype = hton(hrtype);
}


word c_arp_header::get_prtype()
{
    return ntoh(header->prtype);
}


void c_arp_header::set_prtype(word prtype)
{
    header->prtype = hton(prtype);
}


byte c_arp_header::get_hrlen()
{
    return ntoh(header->hrlen);
}


void c_arp_header::set_hrlen(byte hrlen)
{
    header->hrlen = hton(hrlen);

    sha = ((byte*)header) + ARP_HEADER_LEN;
    spa = sha + get_hrlen();
    tha = spa + get_prlen();
    tpa = tha + get_hrlen();
}


byte c_arp_header::get_prlen()
{
    return ntoh(header->prlen);
}


void c_arp_header::set_prlen(byte prlen)
{
    header->prlen = hton(prlen);

    sha = ((byte*)header) + ARP_HEADER_LEN;
    spa = sha + get_hrlen();
    tha = spa + get_prlen();
    tpa = tha + get_hrlen();
}


word c_arp_header::get_operation()
{
    return ntoh(header->operation);
}


void c_arp_header::set_operation(word operation)
{
    header->operation = hton(operation);
}


byte* c_arp_header::get_sha()
{
    return sha;
}


void c_arp_header::set_sha(byte* sha, u_int len)
{
    if(len == 0)
    {
        len = get_hrlen();
    }

    memcpy(c_arp_header::sha, sha, len);
}


byte* c_arp_header::get_spa()
{
    return spa;
}


void c_arp_header::set_spa(byte* spa, u_int len)
{
    if(len == 0)
    {
        len = get_hrlen();
    }

    memcpy(c_arp_header::spa, spa, len);
}


byte* c_arp_header::get_tha()
{
    return tha;
}


void c_arp_header::set_tha(byte* tha, u_int len)
{
    if(len == 0)
    {
        len = get_hrlen();
    }

    memcpy(c_arp_header::tha, tha, len);
}


byte* c_arp_header::get_tpa()
{
    return tpa;
}


void c_arp_header::set_tpa(byte* tpa, u_int len)
{
    if(len == 0)
    {
        len = get_hrlen();
    }

    memcpy(c_arp_header::tpa, tpa, len);
}

