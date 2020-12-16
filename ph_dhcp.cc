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

#include "hr_type.h"
#include "support.h"
#include "ph_packet.h"



c_string dhcp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_dhcp_header header(packet_info.packet);

    output_string.add((char*)"DHCP\tOP %u (",
        header.get_op()); 

    switch(header.get_op())
    {
        case DHCP_OP_BOOTREQUEST:
            output_string.add((char*)"Boot Request");
            break;

        case DHCP_OP_BOOTREPLY:
            output_string.add((char*)"Boot Reply");
            break;

        default:
            output_string.add((char*)"Unknown");
            break;

    }

    output_string.add((char*)")  ");

    output_string.add_hex((char*)"HRTYPE 0x%02X%02X (",
        (word)header.get_hrtype());
  
    output_string += print_arp_hrtype(header.get_hrtype());
 
    output_string.add((char*)")  ");

    output_string.add((char*)"HRLEN %u  HOPS %u\n",
        header.get_hrlen(),
        header.get_hops());

    output_string.add((char*)"\tXID %u  SECS %u",
        header.get_xid(),
        header.get_secs());

    output_string.add_hex((char*)"\tFLAGS 0x%02X%02X |",
        header.get_flags());
  
    if(header.get_flag_b())
    {
        output_string.add((char*)"B|");
    }
    else
    {
        output_string.add((char*)" |");
    }

    output_string.add((char*)"\n");

    string ciaddr_string[16];       
    string yiaddr_string[16];       
    string siaddr_string[16];       
    string giaddr_string[16];
                  
    conv_ip_str(ciaddr_string, header.get_ciaddr());
    conv_ip_str(yiaddr_string, header.get_yiaddr());
    conv_ip_str(siaddr_string, header.get_siaddr());
    conv_ip_str(giaddr_string, header.get_giaddr());

    output_string.add((char*)"\tCLIENT IP ADDR %s  YOUR IP ADDR %s\n"
                      "\tSERVER IP ADDR %s  GATEWAY IP ADDR %s\n",
        ciaddr_string,
        yiaddr_string,
        siaddr_string,
        giaddr_string);

    switch(header.get_hrtype())
    {
        case ARP_HRTYPE_ETHER:
            string mac_addr_str[32];
            output_string.add((char*)"\tCLIENT MAC ADDR %s",
            conv_ether_str(mac_addr_str, header.get_chaddr()));
            break;

        default:
            output_string.add((char*)"\t*** CLIENT HARDWARE ADDRESS NOT SUPPORTED ***");
    }

    output_string.add((char*)"\n");

    if(header.get_sname()[0])
    {
        output_string.add((char*)"\tSNAME %s\n",
            header.get_sname());
    }

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

