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


#ifdef OS_LINUX
    #include <string.h>
#endif


#include <sys/types.h>

#include <netz.h>

#include "ph_packet.h"
#include "support.h"



c_string tcp_options_handler(c_packet_info);
c_string tcp_option_handler(byte*, u_int&);
c_string tcp_option_handler(c_tcpopt_eol);
c_string tcp_option_handler(c_tcpopt_nop);
c_string tcp_option_handler(c_tcpopt_mss);
c_string tcp_option_handler(c_tcpopt_wscale);
c_string tcp_option_handler(c_tcpopt_sackperm);
c_string tcp_option_handler(c_tcpopt_sack);
c_string tcp_option_handler(c_tcpopt_echo);
c_string tcp_option_handler(c_tcpopt_echoreply);
c_string tcp_option_handler(c_tcpopt_timestamp);
c_string tcp_option_handler(c_tcpopt_pocperm);
c_string tcp_option_handler(c_tcpopt_pocsprof);
c_string tcp_option_handler(c_tcpopt_cc);
c_string tcp_option_handler(c_tcpopt_ccnew);
c_string tcp_option_handler(c_tcpopt_ccecho);
c_string tcp_option_handler(c_tcpopt_signature);
c_string tcp_option_handler(c_tcpopt_altcsr);
c_string tcp_option_handler(c_tcpopt_altcsd);
c_string tcp_option_handler(c_tcpopt_generic);



c_string tcp_packet_handler(c_packet_info packet_info)
{
    c_string output_string;

    c_tcp_header header(packet_info.packet);

    output_string.add("TCP\t"); 
    output_string.add("SPORT %u  DPORT %u  SEQ %u  ACK %u  URP %u\n",
        header.get_sport(),
        header.get_dport(),
        header.get_seq(),
        header.get_ack(),  
        header.get_urp());

    output_string.add("\tFLAGS |");

    if(header.get_flag_y())
    {
        output_string.add(" Y |");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_x())
    {
        output_string.add(" X |");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_urg())
    {
        output_string.add("URG|");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_ack())
    {
        output_string.add("ACK|");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_psh())
    {
        output_string.add("PSH|");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_rst())
    {
        output_string.add("RST|");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_syn())
    {
        output_string.add("SYN|");
    }
    else
    {
        output_string.add("   |");
    }

    if(header.get_flag_fin())
    {
        output_string.add("FIN|  ");
    }
    else
    {
        output_string.add("   |  ");
    }

    output_string.add("WIN %u  ",
        header.get_win());

    output_string.add("CKSUM %u ",
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

    if(!cksum(packet_info.packet, packet_info.packet_len, pseudo_header))
    {
        output_string.add("(OK)");
    }
    else
    {
        output_string.add("(BAD)");
    }

    output_string.add("\n");

    output_string.add("\tHLEN %u  PLEN %u  OLEN %u  DLEN %u",
        header.get_hlen(),
        packet_info.packet_len,
        header.get_hlen()  - sizeof(s_tcp_header),
        packet_info.packet_len - header.get_hlen());


    output_string += tcp_options_handler(packet_info);

    
    output_string.add("\n");

    output_string += debug(packet_info);

    output_string += print_line();

    return output_string;
}


c_string tcp_options_handler(c_packet_info packet_info)
{
    c_string output_string;

    if(packet_info.tcp_options)
    {
        c_string options_string;

        u_int pos = 0;
    
        while(pos < packet_info.tcp_options_len)
        {
            options_string += tcp_option_handler(packet_info.tcp_options, pos);
        }

        output_string += print_options_string(options_string);
    }

    return output_string;
}


c_string tcp_option_handler(byte* options, u_int& pos)
{
    c_string option_string;

    option_string.add("["); 
            
    switch(c_tcpopt_generic(options + pos).get_code())
    {
        case TCPOPT_EOL: {
            c_tcpopt_eol option(options + pos); 
            pos += option.get_len() + 64;
            option_string += tcp_option_handler(option);
            break;
        }

        case TCPOPT_NOP: {
            c_tcpopt_nop option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

	case TCPOPT_MSS: {
            c_tcpopt_mss option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option);
            break;
        }

        case TCPOPT_WSCALE: {
            c_tcpopt_wscale option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break; 
        }
              
        case TCPOPT_SACKPERM: {
            c_tcpopt_sackperm option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_SACK: {
            c_tcpopt_sack option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_ECHO: {
            c_tcpopt_echo option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_ECHOREPLY: {
            c_tcpopt_echoreply option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_TIMESTAMP: {
            c_tcpopt_timestamp option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option);
            break; 
        }

        case TCPOPT_POCPERM: {
            c_tcpopt_pocperm option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option);
            break; 
        }

        case TCPOPT_POCSPROF: {
            c_tcpopt_pocsprof option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option);
            break; 
        }

        case TCPOPT_CC: {
            c_tcpopt_cc option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_CCNEW: {
            c_tcpopt_ccnew option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_CCECHO: {
            c_tcpopt_ccecho option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_ALTCSR: {
            c_tcpopt_altcsr option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_ALTCSD: {
            c_tcpopt_altcsd option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option); 
            break;
        }

        case TCPOPT_SIGNATURE: {
            c_tcpopt_signature option(options + pos);
            pos += option.get_len();
            option_string += tcp_option_handler(option);
            break;
        }

        default: {
            c_tcpopt_generic option(options + pos); 
            pos += option.get_len();
            option_string += tcp_option_handler(option);
        }
    }

    option_string.add("] ");

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_eol)
{
    c_string option_string;

    option_string.add("eol");
 
    return option_string;
}


c_string tcp_option_handler(c_tcpopt_nop)
{
    c_string option_string;

    option_string.add("nop");

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_mss option)
{
    c_string option_string;

    option_string.add("mss %u", 
        option.get_size());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_wscale option)
{
    c_string option_string;

    option_string.add("wscale %u",
        option.get_scale());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_sackperm option)
{
    c_string option_string;

    option_string.add("sackperm");

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_sack option)
{
    c_string option_string;

    u_int sack_blocks = (option.get_len() - TCPOPT_SACK_LEN)
        / TCPOPT_SACK_DATALEN; 

    option_string.add("sack (%u) ",
        sack_blocks);

    for(u_int i = 0; i < sack_blocks; i++)
    {
        option_string.add("{%u:%u}",
            option.get_ledge(i) + 1,
            option.get_redge(i) + 1);
        
        if(i + 1 < sack_blocks)
        {
            option_string.add(" ");
        }
    }

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_echo option)
{
    c_string option_string;

    option_string.add("echo %u", 
        option.get_info());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_echoreply option)
{
    c_string option_string;

    option_string.add("echoreply %u", 
        option.get_info());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_timestamp option)
{
    c_string option_string;

    option_string.add("timestamp %u, %u",
        option.get_tsval(),
        option.get_tsecr()); 

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_pocperm option)
{
    c_string option_string;

    option_string.add("pocperm"); 

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_pocsprof option)
{
    c_string option_string;

    option_string.add("pocsprof %u %u", 
        option.get_sflag(),
        option.get_eflag());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_cc option)
{
    c_string option_string;

    option_string.add("cc %u",
        option.get_segment());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_ccnew option)
{
    c_string option_string;

    option_string.add("ccnew %u",
        option.get_segment());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_ccecho option)
{
    c_string option_string;

    option_string.add("ccecho %u",
        option.get_segment());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_altcsr option)
{
    c_string option_string;

    option_string.add("altcsr %u",
        option.get_cksum());

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_altcsd option)
{
    c_string option_string;

    option_string.add("altcsd {");
  
    for(u_int i = 0; i < (u_int)(option.get_len() - 2); i ++)
    {
        option_string.add_hex("0x%02X",
            (byte)*(option.get_data() + i));

        if(i + 1 < (u_int)(option.get_len() - 2))
        {
            option_string.add(" ");
        } 
    }
    
    option_string.add("}");

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_signature option)
{
    c_string option_string;

    option_string.add("signature ");
    option_string.add_raw((byte*)option.get_signature(), 16);

    return option_string;
}


c_string tcp_option_handler(c_tcpopt_generic option)
{
    c_string option_string;

    option_string.add("unknown %u %u(%u) {",
        option.get_code(),
        option.get_len(),
        option.get_len() - 2);
 
    for(u_int i = 0; i < (u_int)(option.get_len() - 2); i ++)
    {
        option_string.add_hex("0x%02X",
            (byte)*(option.get_data() + i));

        if(i + 1 < (u_int)(option.get_len() - 2))
        {
            option_string.add(" ");
        } 
    }
    
    option_string.add("}");

    return option_string;
}

