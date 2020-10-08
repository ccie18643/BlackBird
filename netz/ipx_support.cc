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


#include "ipx_support.h"


c_ipx_header::c_ipx_header(byte* ipx_header)
{
    header = (s_ipx_header*)ipx_header;
}


c_ipx_header::c_ipx_header(s_ipx_header* ipx_header)
{
    header = ipx_header;
}


word c_ipx_header::get_cksum()
{
    return ntoh(header->cksum);
}


void c_ipx_header::set_cksum(word cksum)
{
    header->cksum = cksum;
}


word c_ipx_header::get_len()
{
    return ntoh(header->len);
}


void c_ipx_header::set_len(word len)
{
    header->len = hton(len);
}


byte c_ipx_header::get_tcontrol()
{
    return ntoh(header->tcontrol);
}


void c_ipx_header::set_tcontrol(byte tcontrol)
{
    header->tcontrol = hton(tcontrol);
}


byte c_ipx_header::get_ptype()
{
    return ntoh(header->ptype);
}


void c_ipx_header::set_ptype(byte ptype)
{
    header->ptype = hton(ptype);
}


dword c_ipx_header::get_dnet()
{
    return ntoh(header->dnet);
}


void c_ipx_header::set_dnet(dword dnet)
{
    header->ptype = hton(dnet);
}


byte* c_ipx_header::get_dnode()
{
    return header->dnode;
}


void c_ipx_header::set_dnode(byte* dnode)
{
    memcpy(header->dnode, dnode, sizeof(header->dnode));
}


word c_ipx_header::get_dsock()
{
    return ntoh(header->dsock);
}


void c_ipx_header::set_dsock(word dsock)
{
    header->dsock = hton(dsock);
}


dword c_ipx_header::get_snet()
{
    return ntoh(header->snet);
}


void c_ipx_header::set_snet(dword snet)
{
    header->snet = hton(snet);
}


byte* c_ipx_header::get_snode()
{
    return header->snode;
}


void c_ipx_header::set_snode(byte* snode)
{
    memcpy(header->dnode, snode, sizeof(header->snode));
}


word c_ipx_header::get_ssock()
{
    return ntoh(header->ssock);
}


void c_ipx_header::set_ssock(word ssock)
{
    header->ssock = hton(ssock);
}

