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


#include "ip6_support.h"
#include "support.h"
#include "cksum.h"


c_ip6_header::c_ip6_header(byte* ip6_header)
{
    header = (s_ip6_header*)ip6_header;
}


c_ip6_header::c_ip6_header(s_ip6_header* ip6_header)
{
    header = ip6_header;
}


byte c_ip6_header::get_ver()
{
    return bits(ntoh(header->vcf), IP6_VERSION_MASK);
}


void c_ip6_header::set_ver(byte ver)
{
    header->vcf = hton(bits(ntoh(header->vcf), IP6_VERSION_MASK, ver));
}


byte c_ip6_header::get_tclass()
{
    return bits(ntoh(header->vcf), IP6_TCLASS_MASK);
}


void c_ip6_header::set_tclass(byte tclass)
{
    header->vcf = hton(bits(ntoh(header->vcf), IP6_TCLASS_MASK, tclass));
}


dword c_ip6_header::get_flabel()
{
    return bits(ntoh(header->vcf), IP6_FLABEL_MASK);
}


void c_ip6_header::set_flabel(dword flabel)
{
    header->vcf = hton(bits(ntoh(header->vcf), IP6_FLABEL_MASK, flabel));
}


word c_ip6_header::get_plen()
{
    return ntoh(header->plen);
}


void c_ip6_header::set_plen(word plen)
{
    header->plen = hton(plen);
}


byte c_ip6_header::get_next()
{
    return ntoh(header->next);
}


void c_ip6_header::set_next(byte next)
{
    header->next = hton(next);
}


byte c_ip6_header::get_hlimit()	
{
    return ntoh(header->hlimit);
}


void c_ip6_header::set_hlimit(byte hlimit)
{
    header->hlimit = hton(hlimit);
}


byte c_ip6_header::get_src(u_int n)
{
    return ntoh(header->src[n]);
}


void c_ip6_header::set_src(u_int n, byte srcbyte)
{
    header->src[n] = hton(srcbyte);
}


byte c_ip6_header::get_dst(u_int n)
{
    return ntoh(header->dst[n]);
}


void c_ip6_header::set_dst(u_int n, byte dstbyte)
{
    header->dst[n] = hton(dstbyte);
}
   
 
byte* c_ip6_header::get_src()
{
    return header->src;
}


void c_ip6_header::set_src(byte* src)
{
    memcpy(header->src, src, IP6_ADDR_LEN);
}


byte* c_ip6_header::get_dst()
{
    return header->dst;
}


void c_ip6_header::set_dst(byte* dst)
{
    memcpy(header->dst, dst, IP6_ADDR_LEN);
}


c_ip6p_header::c_ip6p_header(c_ip6_header ip6_header)
{
    memcpy(ip6p_header.src, ip6_header.get_src(), IP6_ADDR_LEN);
    memcpy(ip6p_header.dst, ip6_header.get_dst(), IP6_ADDR_LEN);
    ip6p_header.plen = hton(ip6_header.get_plen());
    ip6p_header.pad[0] = 0;
    ip6p_header.pad[1] = 0;
    ip6p_header.pad[2] = 0;
    ip6p_header.next = hton(ip6_header.get_next());
}


c_pseudo_header c_ip6p_header::get_pseudo_header()
{
    c_pseudo_header pseudo_header;
 
    memcpy(pseudo_header.header, (byte*)&ip6p_header, IP6P_HEADER_LEN);
 
    pseudo_header.header_len = IP6P_HEADER_LEN;
    pseudo_header.header_type = PSEUDO_HEADER_TYPE_IP6;
 
    return pseudo_header;
}
