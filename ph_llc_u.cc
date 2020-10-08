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



c_string print_sap(byte);


c_string llc_u_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_llc_u_header header(packet_info.packet);

    output_string.add("LLC U\t");

    output_string.add_hex("DSAP 0x%02X ",
        header.get_dsap());
 
    output_string.add_bin("(%u%u%u%u%u%u%u|%u) (",
        header.get_dsap());

    output_string += print_sap(header.get_dsap());

    if(header.get_dsap_ig())
    {
        output_string.add(", Group Address");
    }
    else
    {
        output_string.add(", Individual Address");
    }

    output_string.add(")\n");

    output_string.add_hex("\tSSAP 0x%02X ",
        header.get_ssap());
 
    output_string.add_bin("(%u%u%u%u%u%u%u|%u) (",
        header.get_ssap());

    output_string += print_sap(header.get_ssap());

    if(header.get_ssap_cr())
    {
        output_string.add(", Response");
    }
    else
    {
        output_string.add(", Command");
    }

    output_string.add(")\n");

    output_string.add("\tCTRL ");

    output_string.add_hex("0x%02X ",
        header.get_ctrl());

    output_string.add_bin("(%u%u%u|%u|%u%u|%u%u) ",
            header.get_ctrl());

    output_string.add("(U-type");


    if(header.get_ctrl_pf())
    {
        if(header.get_ssap_cr())
        {
            output_string.add(", Finall");
        }
        else
        {
            output_string.add(", Poll");
        }
    }


    switch(header.get_ctrl_m())
    {
        case LLC_U_M_UI:
            output_string.add(", UI");
            break;

        case LLC_U_M_SABME: 
            output_string.add(", SABME");
            break;
 
        case LLC_U_M_DISC: 
            output_string.add(", DISC");
            break;
 
        case LLC_U_M_UA: 
            output_string.add(", UA");
            break;
 
        case LLC_U_M_DM: 
            output_string.add(", DM");
            break;
 
        case LLC_U_M_FRMR:
            output_string.add(", FRMR");
            break;
 
        case LLC_U_M_XID:
            output_string.add(", XID");
            break;
 
        case LLC_U_M_TEST:      
            output_string.add(", TEST");
            break;
    }
    
    output_string.add(")");

    output_string.add("\n");

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}

