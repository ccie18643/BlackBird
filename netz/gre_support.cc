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


#include "gre_support.h"
#include "support.h"

c_gre_header::c_gre_header(byte* gre_header)
{
    header = (s_gre_header*)gre_header;

    if(get_flag_cksum() | get_flag_routing())
    {
        cksum = (word*)(header + GRE_HEADER_LEN);
        offset = (word*)(header + GRE_HEADER_LEN + GRE_CKSUM_LEN);
    }
 
    if(get_flag_key())
    {
        key = (dword*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()));
    }

    if(get_flag_seq())
    {
        seq = (dword*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()) + GRE_KEY_LEN * get_flag_key());
    }

    if(get_flag_routing())
    {
        routing = (void*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()) + GRE_KEY_LEN * get_flag_key()
            + GRE_SEQ_LEN * get_flag_seq());
    }
}


c_gre_header::c_gre_header(s_gre_header* gre_header)
{
    header = gre_header;

    if(get_flag_cksum() | get_flag_routing())
    {
        cksum = (word*)(header + GRE_HEADER_LEN);
        offset = (word*)(header + GRE_HEADER_LEN + GRE_CKSUM_LEN);
    }

    if(get_flag_key())
    {
        key = (dword*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()));
    }    

    if(get_flag_seq())
    {
        seq = (dword*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()) + GRE_KEY_LEN * get_flag_key());
    }

    if(get_flag_routing())
    {
        routing = (void*)(header + GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
            * (get_flag_cksum() | get_flag_routing()) + GRE_KEY_LEN * get_flag_key()
            + GRE_SEQ_LEN * get_flag_seq());
    }
}


u_int c_gre_header::get_len()
{
    u_int len = GRE_HEADER_LEN + (GRE_CKSUM_LEN + GRE_OFFSET_LEN)
        * (get_flag_cksum() | get_flag_routing()) + GRE_KEY_LEN * get_flag_key() 
        + GRE_SEQ_LEN * get_flag_seq() + GRE_ROUTING_LEN * get_flag_routing();

    if(get_flag_routing())
    {
        s_gre_sre* sre = (s_gre_sre*)routing;

        u_int i = 0;

        while(sre[i].af & sre[i].len)
        {
            len += sre[i].len; 
            i++;
        }
    }
  
    return len;
}

word c_gre_header::get_frrv()
{
    return ntoh(header->frrv);
}


byte c_gre_header::get_flag_cksum()
{
    return bits(get_frrv(), GRE_FRRV_FLAG_CKSUM_MASK);
}


byte c_gre_header::get_flag_routing()
{
    return bits(get_frrv(), GRE_FRRV_FLAG_ROUTING_MASK);
}


byte c_gre_header::get_flag_key()
{
    return bits(get_frrv(), GRE_FRRV_FLAG_KEY_MASK);
}


byte c_gre_header::get_flag_seq()
{
    return bits(get_frrv(), GRE_FRRV_FLAG_SEQ_MASK);
}


byte c_gre_header::get_flag_ssr()
{
    return bits(get_frrv(), GRE_FRRV_FLAG_SSR_MASK);
}


byte c_gre_header::get_recur()
{
    return bits(get_frrv(), GRE_FRRV_RECUR_MASK);
}


byte c_gre_header::get_ver()
{
    return bits(get_frrv(), GRE_FRRV_VER_MASK);
}


word c_gre_header::get_type()
{ 
    return ntoh(header->type);
}


word c_gre_header::get_cksum()
{
    return ntoh(*cksum);
}


word c_gre_header::get_offset()
{
    return ntoh(*offset);
}


dword c_gre_header::get_key()
{
    return ntoh(*key);
}

dword c_gre_header::get_seq()
{
    return ntoh(*seq);
}


