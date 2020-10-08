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

#include "ph_packet.h"
#include "support.h"


c_string print_igmp_info(u_int);


c_string igmp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_igmp_header header(packet_info.packet);

    output_string.add("IGMP\t");
    output_string.add("TYPE %u  CODE %u ",
        header.get_type(),
        header.get_code()); 

    output_string += print_igmp_info(header.get_type());

    string igmp_group_string[16];

    conv_ip_str(igmp_group_string, header.get_group());

    output_string.add("  GROUP %s  CKSUM %u ",
        igmp_group_string,
        header.get_cksum()); 

    if(!cksum((byte*)header.get_header(), sizeof(s_igmp_header)))
    {
        output_string.add("(OK)");
    }
    else
    {
        output_string.add("(BAD)");
    }

    output_string.add("\n");	 

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}


c_string print_igmp_info(u_int type)
{
    switch(type)
    {
        case IGMP_HOST_MEMBERSHIP_QUERY:
            return c_string("membership querry");

        case IGMP_V1_HOST_MEMBERSHIP_REPORT:
            return c_string("v1 membership report");

        case IGMP_DVMRP:
            return c_string("DVMRP routing message");

        case IGMP_PIM:
            return c_string("PIM routing message");

        case IGMP_V2_HOST_MEMBERSHIP_REPORT:
            return c_string("v2 membersip report");

        case IGMP_HOST_LEAVE_MESSAGE:
            return c_string("leave-group message");

        case IGMP_MTRACE_REPLY:
            return c_string("traceroute reply");

        case IGMP_MTRACE_QUERY:
            return c_string("traceroute query");

        default:
            return c_string("unknown");
    }
}

