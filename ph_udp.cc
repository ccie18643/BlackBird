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


#include <netz.h>

#include "support.h"
#include "ph_packet.h"



c_string udp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_udp_header header(packet_info.packet);

    output_string.add((char*)"UDP\t"); 
    output_string.add((char*)"SPORT %u  DPORT %u  CKSUM %u ",
        header.get_sport(),
        header.get_dport(),
        header.get_cksum());


    c_pseudo_header pseudo_header;

    if(packet_info.previous_packet_type == PACKET_TYPE_IP)
    {
        c_ipp_header ipp_header(c_ip_header(packet_info.previous_packet));
        pseudo_header = ipp_header.get_pseudo_header();
    }

    if(packet_info.previous_packet_type == PACKET_TYPE_IP6)
    {
        c_ip6p_header ip6p_header(c_ip6_header(packet_info.previous_packet));
        pseudo_header = ip6p_header.get_pseudo_header();
    }

    if(header.get_cksum() == 0)
    {
        output_string.add((char*)"(NONE)");
    }
    else 
    {
        if(!cksum(packet_info.packet, packet_info.packet_len, pseudo_header))
        {
            output_string.add((char*)"(OK)");
        }
        else
        {
            output_string.add((char*)"(BAD)");
        }
    }

    output_string.add((char*)"\n");


    output_string.add((char*)"\tHLEN %u  PLEN %u  DLEN %u\n",
        UDP_HEADER_LEN,
        header.get_len(),
        header.get_len() - UDP_HEADER_LEN);


    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

