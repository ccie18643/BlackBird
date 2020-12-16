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




c_string igrp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_igrp_header header(packet_info.packet);

    output_string.add((char*)"IGRP\t");

    output_string.add((char*)"VER %u  OPCODE %u ",
        header.get_ver(),
        header.get_opcode());


    switch(header.get_opcode()) {

        case IGRP_OPCODE_UPDATE: 
            output_string += "(Update)";
            break;

        case IGRP_OPCODE_REQUEST: 
            output_string += "(Request)";
            break;

        default:
            output_string += "(Unknown)";
    }


    output_string.add((char*)"  EDITION %u  AS %u\n\tINTERIOR %u  SYSTEM %u  EXTERIOR %u  CKSUM %u ",
        header.get_edition(),
        header.get_as(),
        header.get_interior(),
        header.get_system(),
        header.get_exterior(),
        header.get_cksum());

    if(!cksum(packet_info.packet, packet_info.packet_len))
    {
        output_string.add((char*)"(OK)");
    }
    else
    {
        output_string.add((char*)"(BAD)");
    }


    if(header.get_opcode() == IGRP_OPCODE_UPDATE)
    {
        for(int i = 0; i < header.get_interior(); i++)
        {
            c_igrp_update update(packet_info.packet + IGRP_HEADER_LEN
                + i * IGRP_UPDATE_LEN);

            string net_string[16];

            conv_ip_str(net_string, update.get_intnet());

            output_string.add((char*)"\n\n\tINTERIOR NETWORK %s  HOPCOUNT %u\n",
                net_string,
                update.get_hopcount());

            output_string.add(
                (char*)"\tBW %u (%u Kbit)  DELAY %u (%u usec)  MTU %u  REL %u",
                update.get_bandwidth(),
                10000000 / update.get_bandwidth(),
                update.get_delay(),
                update.get_delay() * 10,
                update.get_mtu(),
                update.get_reliability());
        }


        for(int i = 0; i < header.get_system(); i++)
        {
            c_igrp_update update(packet_info.packet + IGRP_HEADER_LEN 
                + header.get_interior() * IGRP_UPDATE_LEN 
                + i * IGRP_UPDATE_LEN);

            string net_string[16];

            conv_ip_str(net_string, update.get_net());

            output_string.add((char*)"\n\n\tSYSTEM NETWORK %s  HOPCOUNT %u\n",
                net_string,
                update.get_hopcount());

            output_string.add(
                (char*)"\tBW %u (%u Kbit)  DELAY %u (%u usec)  MTU %u  REL %u",
                update.get_bandwidth(),
                10000000 / update.get_bandwidth(),
                update.get_delay(),
                update.get_delay() * 10,
                update.get_mtu(),
                update.get_reliability());
        }


        for(int i = 0; i < header.get_exterior(); i++)
        {
            c_igrp_update update(packet_info.packet + IGRP_HEADER_LEN 
                + header.get_interior() * IGRP_UPDATE_LEN 
                + header.get_system() * IGRP_UPDATE_LEN
                + i * IGRP_UPDATE_LEN);

            string net_string[16];

            conv_ip_str(net_string, update.get_net());

            output_string.add((char*)"\n\n\tEXTERIOR NETWORK %s  HOPCOUNT %u\n",
                net_string,
                update.get_hopcount());

            output_string.add(
                (char*)"\tBW %u (%u Kbit)  DELAY %u (%u usec)  MTU %u  REL %u",
                update.get_bandwidth(),
                10000000 / update.get_bandwidth(),
                update.get_delay(),
                update.get_delay() * 10,
                update.get_mtu(),
                update.get_reliability());
        }
    }

    output_string.add((char*)"\n");

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

