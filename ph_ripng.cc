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



c_string ripng_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_rip_header header(packet_info.packet);

    output_string.add((char*)"RIPng\t"); 
    output_string.add((char*)"CMD %u (",
        header.get_cmd());

    switch(header.get_cmd())
    {
        case RIP_CMD_REQUEST : 
            output_string.add((char*)"REQUEST");
            break;

        case RIP_CMD_RESPONSE : 
            output_string.add((char*)"RESPONSE");
            break;

        default:
            output_string.add((char*)"UNKNOWN");
    }    


    output_string.add((char*)")  VER %u\n",
        header.get_ver());


    for(u_int i = 0; i < (packet_info.packet_len - RIPNG_HEADER_LEN) / RIPNG_ENTRY_LEN; i++)
    {
        switch(header.get_ver())
        {
            case 1 :
            {
                c_ripng_route_entry route_entry(packet_info.packet + RIPNG_HEADER_LEN
                    + i * RIPNG_ENTRY_LEN);

                if(route_entry.get_metric() != 0xFF)
                {
                    output_string.add((char*)"\n[ROUTE]\t");

                    string prefix_string[40];

                    output_string.add((char*)"PREFIX %s/%u  TAG %u  HOP %u",
                        conv_ip6_str(prefix_string, route_entry.get_prefix()),
                        route_entry.get_prefix_len(),
                        route_entry.get_tag(),
                        route_entry.get_metric());
                }
                else
                {
                    c_ripng_next_hop_entry next_hop_entry(packet_info.packet
                        + RIPNG_HEADER_LEN + i * RIPNG_ENTRY_LEN);

                    output_string.add((char*)"\n[NHOP]\t");

                    string prefix_string[40];

                    output_string.add((char*)"NHOP %s",
                        conv_ip6_str(prefix_string, next_hop_entry.get_next_hop()));
                }

                break;
            }
        }

        output_string.add((char*)"\n");
    }



    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}


