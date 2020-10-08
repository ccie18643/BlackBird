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


#include "dhcp_support.h"
#include "support.h"

c_dhcp_header::c_dhcp_header(byte* dhcp_header)
{
    header = (s_dhcp_header*)dhcp_header;
}


c_dhcp_header::c_dhcp_header(s_dhcp_header* dhcp_header)
{
    header = dhcp_header;
}


byte c_dhcp_header::get_op()
{
    return ntoh(header->op);
}


byte c_dhcp_header::get_hrtype()
{
    return ntoh(header->hrtype);
}


byte c_dhcp_header::get_hrlen()
{
    return ntoh(header->hrlen);
}


byte c_dhcp_header::get_hops()
{
    return ntoh(header->hops);
}


dword c_dhcp_header::get_xid()
{
    return ntoh(header->xid);
}


word c_dhcp_header::get_secs()
{
    return ntoh(header->secs);
}


word c_dhcp_header::get_flags()
{
    return ntoh(header->flags);
}


byte c_dhcp_header::get_flag_b()
{
    return bits(get_flags(), DHCP_FLAG_B_MASK);
}


dword c_dhcp_header::get_ciaddr()
{
    return header->ciaddr;
}


dword c_dhcp_header::get_yiaddr()
{
    return header->yiaddr;
}


dword c_dhcp_header::get_siaddr()
{
    return header->siaddr;
}


dword c_dhcp_header::get_giaddr()
{
    return header->giaddr;
}


byte* c_dhcp_header::get_chaddr()
{
    return header->chaddr;
}


byte* c_dhcp_header::get_sname()
{
    return header->sname;
}


byte* c_dhcp_header::get_file()
{
    return header->file;
}


