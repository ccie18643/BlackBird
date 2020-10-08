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

#include "ether_type.h"
#include "support.h"
#include "ph_packet.h"



c_string gre_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_gre_header header(packet_info.packet);

    output_string.add("GRE\tFLAGS |"); 

    if(header.get_flag_cksum())
    {
        output_string.add("C|");
    }
    else
    {
        output_string.add(" |");
    }

    if(header.get_flag_routing())
    {
        output_string.add("R|");
    }
    else
    {
        output_string.add(" |");
    }

    if(header.get_flag_key())
    {
        output_string.add("K|");
    }
    else
    {
        output_string.add(" |");
    }

    if(header.get_flag_seq())
    {
        output_string.add("S|");
    }
    else
    {
        output_string.add(" |");
    }

    if(header.get_flag_ssr())
    {
        output_string.add("s|");
    }
    else
    {
        output_string.add(" |");
    }


    output_string.add("  RECUR %u  VER %u  ",
        header.get_recur(),
        header.get_ver());

    output_string.add_hex("TYPE 0x%02X%02X (",
        header.get_type());
 
    output_string += print_ether_type(header.get_type());
  
    output_string.add(")");


    if(header.get_flag_cksum() | header.get_flag_routing() | header.get_flag_key()
        | header.get_flag_seq() | header.get_flag_routing())
    {
        output_string.add("\n\t");
    }

    if(header.get_flag_cksum())
    {
        output_string.add("CKSUM %u ",
            header.get_cksum()); 

        if(!cksum(packet_info.packet, packet_info.packet_len))
        {
            output_string.add("(OK)");
        }
        else
        {
            output_string.add("(BAD)");
        }

        output_string.add("  ");
    }

    if(header.get_flag_routing())
    {
        output_string.add("OFFSET %u  ",
            header.get_offset());
    }

    if(header.get_flag_key())
    {
        output_string.add("KEY %u  ",
            header.get_key());
    }

    if(header.get_flag_seq())
    {
        output_string.add("SEQ %u  ",
            header.get_offset());
    }

    output_string.add("\n");

    if(header.get_flag_routing())
    {
        output_string.add("\n");

        /* missing SRR handler here */
    }


    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

