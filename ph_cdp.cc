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


c_string cdp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_cdp_header header(packet_info.packet);

    output_string.add("CDP\t"); 
    output_string.add("VER %u  TTL %u  CKSUM %u ",
        header.get_ver(),
        header.get_ttl(),
        header.get_cksum());

    if(!cksum(packet_info.packet, packet_info.packet_len))
    {
        output_string.add("(OK)");
    }
    else
    {
        output_string.add("(BAD)");
    }

    output_string.add("\n");

    byte* cdp_data = packet_info.packet + CDP_HEADER_LEN;

    while(cdp_data < packet_info.packet + packet_info.packet_len)
    {
        c_cdp_dheader dheader(cdp_data);

        output_string.add_hex("\tTYPE 0x%02X%02X (",
            dheader.get_type());

        switch(dheader.get_type()) {

            case CDP_DHEADER_TYPE_DEVICE_ID:
                output_string += "Device ID";
                break;

            case CDP_DHEADER_TYPE_ADDRESS:
                output_string += "Address";
                break;

            case CDP_DHEADER_TYPE_PORT_ID:
                output_string += "Port ID";
                break;

            case CDP_DHEADER_TYPE_CAPABILITIES:
                output_string += "Capabil.";
                break;

            case CDP_DHEADER_TYPE_VERSION:
                output_string += "Version";
                break;

            case CDP_DHEADER_TYPE_PLATFORM:
                output_string += "Platform";
                break;

            case CDP_DHEADER_TYPE_IP_PREFIX:
                output_string += "IP Prefix";
                break;

            default:
                output_string += "Unknown";

        }

        output_string.add(")\t  LEN %u  ",
            dheader.get_len());


        output_string += "\n";

        cdp_data += dheader.get_len();
    }

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

