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


#include "ether_support.h"
#include "support.h"


c_ether_header::c_ether_header(byte* ether_header)
{
    header = (s_ether_header*)ether_header;
}


c_ether_header::c_ether_header(s_ether_header* ether_header)
{
    header = ether_header;
}


byte* c_ether_header::get_raw()
{
    return (byte*)header;
}


byte* c_ether_header::get_dst()
{
    return header->dst;
}


void c_ether_header::set_dst(byte* dst)
{
    memcpy(header->dst, dst, ETHER_ADDR_LEN);
}


byte* c_ether_header::get_src()
{
    return header->src;
}


void c_ether_header::set_src(byte* src)
{
    memcpy(header->src, src, ETHER_ADDR_LEN);
}


word c_ether_header::get_type()
{
    return ntoh(header->type);
}


void c_ether_header::set_type(word type)
{
    header->type = hton(type);
}

