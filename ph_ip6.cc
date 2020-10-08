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


#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include <netz.h>

#include "ip_proto.h"
#include "ph_packet.h"
#include "support.h"


c_string ip6_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_ip6_header header(packet_info.packet);

    output_string.add("IPv6\t");

    string addr_string[40];

    output_string.add("SRC %s\n", conv_ip6_str(addr_string,
        header.get_src()));

    output_string.add("\t");

    output_string.add("DST %s\n", conv_ip6_str(addr_string,
        header.get_dst()));

    output_string.add(
        "\tVER %u  TCLASS %u  FLABEL %u  PLEN %u  NEXT 0x%02X (",
        header.get_ver(),
        header.get_tclass(),
        header.get_flabel(),
        header.get_plen(),
        header.get_next()); 

    output_string += print_ip_proto(header.get_next());

    output_string.add(")  HLIMIT %u\n",
        header.get_hlimit());

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

