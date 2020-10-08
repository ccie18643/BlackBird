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


#include "udp_advsupp.h"
#include "ip_support.h"
#include "ip6_support.h"
#include "cksum.h"


c_udp_packet::c_udp_packet(word sport, word dport)
{
    c_udp_header header(packet);

    header.set_sport(sport);
    header.set_dport(dport);
    header.set_len();
    header.set_cksum(0);

    header_len = UDP_HEADER_LEN;
    packet_len = header_len;
}


void c_udp_packet::add_data(byte* data, u_int data_len)
{
    memcpy(packet + header_len, data, data_len);

    packet_len = header_len + data_len;
}


void c_udp_packet::verify()
{
    c_udp_header header(packet);

    header.set_len(packet_len);

    header.set_cksum();
}


void c_udp_packet::verify(c_pseudo_header pseudo_header)
{
    c_udp_header header(packet);

    header.set_len(packet_len);

    header.set_cksum();
    header.set_cksum(cksum(packet, packet_len, pseudo_header));
}

