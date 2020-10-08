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

#ifdef OS_OPENBSD
   #include <memory.h>
#endif

#ifdef OS_LINUX
    #include <string.h>
#endif


#include "tcp_advsupp.h"
#include "ip_support.h"
#include "ip6_support.h"
#include "cksum.h"


c_tcp_packet::c_tcp_packet(word sport, word dport, dword seq, dword ack,
                           byte flags, word win, word urp) 
{
    c_tcp_header tcp_header(packet);

    tcp_header.set_sport(sport);
    tcp_header.set_dport(dport);
    tcp_header.set_seq(seq);
    tcp_header.set_ack(ack);
    tcp_header.set_hlen();
    tcp_header.set_win(win);
    tcp_header.set_flags(flags);
    tcp_header.set_cksum();    
    tcp_header.set_urp(urp);
    
    header_len = TCP_HEADER_LEN;
    packet_len = header_len; 
}


void c_tcp_packet::add_data(byte* data, u_int data_len)
{
    if(header_len & 3)
    {
        add_opt_nop(4 - header_len & 3);
    }
 
    memcpy(packet + header_len, data, data_len);

    packet_len = header_len + data_len;
}


void c_tcp_packet::verify()
{
    c_tcp_header header(packet);

    if(header_len == packet_len)    
    {
        if(header_len & 3)
        {
            add_opt_nop(4 - (header_len & 3));
        }
    }

    header.set_hlen(header_len);
    header.set_cksum();
}


void c_tcp_packet::verify(c_pseudo_header pseudo_header)
{
    c_tcp_header header(packet);

    if(header_len == packet_len)    
    {
        if(header_len & 3)
        {
            add_opt_nop(4 - (header_len & 3));
        }
    }

    header.set_hlen(header_len);
    header.set_cksum();
    header.set_cksum(cksum(packet, packet_len, pseudo_header)); 
}


void c_tcp_packet::add_opt_eol()
{
    c_tcpopt_eol option(packet + header_len);  

    option.set_code();

    header_len += TCPOPT_EOL_LEN;
    packet_len += TCPOPT_EOL_LEN;
}


void c_tcp_packet::add_opt_nop(u_int count)
{
    for(u_int i = 0; i < count; i++)
    {
        c_tcpopt_nop option(packet + header_len);
        
        option.set_code();
    
        header_len += TCPOPT_NOP_LEN;
        packet_len += TCPOPT_NOP_LEN;
    }
}


void c_tcp_packet::add_opt_mss(word size)
{
    c_tcpopt_mss option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_size(size);
    
    header_len += TCPOPT_MSS_LEN;
    packet_len += TCPOPT_MSS_LEN;
}


void c_tcp_packet::add_opt_wscale(byte scale)
{
    c_tcpopt_wscale option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_scale(scale);
    
    header_len += TCPOPT_WSCALE_LEN;
    packet_len += TCPOPT_WSCALE_LEN;
}


void c_tcp_packet::add_opt_sackperm()
{
    c_tcpopt_sackperm option(packet + header_len);

    option.set_code();
    option.set_len();
    
    header_len += TCPOPT_SACKPERM_LEN;
    packet_len += TCPOPT_SACKPERM_LEN;
}


void c_tcp_packet::add_opt_sack(dword* data, u_int data_len)
{
    c_tcpopt_sack option(packet + header_len);
    
    option.set_code();
    option.set_len(TCPOPT_SACK_LEN + data_len);

    for(u_int i = 0; i < data_len / TCPOPT_SACK_DATALEN; i++)
    {
        option.set_ledge(i, data[i * 2]);
        option.set_ledge(i, data[i * 2  +1]);
    }

    header_len += TCPOPT_SACK_LEN + data_len;
    packet_len += TCPOPT_SACK_LEN + data_len;
}


void c_tcp_packet::add_opt_echo(dword info)
{
    c_tcpopt_echo option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_info(info);

    header_len += TCPOPT_ECHO_LEN;
    packet_len += TCPOPT_ECHO_LEN;
}

void c_tcp_packet::add_opt_echoreply(dword info)
{
    c_tcpopt_echoreply option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_info(info);

    header_len += TCPOPT_ECHOREPLY_LEN;
    packet_len += TCPOPT_ECHOREPLY_LEN;
}


void c_tcp_packet::add_opt_timestamp(dword tsval, dword tsecr)
{
    c_tcpopt_timestamp option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_tsval(tsval);
    option.set_tsecr(tsecr);

    header_len += TCPOPT_TIMESTAMP_LEN;
    packet_len += TCPOPT_TIMESTAMP_LEN;
}


void c_tcp_packet::add_opt_pocperm()
{
    c_tcpopt_pocperm option(packet + header_len);

    option.set_code();
    option.set_len();

    header_len += TCPOPT_POCPERM_LEN;
    packet_len += TCPOPT_POCPERM_LEN;
}


void c_tcp_packet::add_opt_pocsprof(byte sflag, byte eflag)
{
    c_tcpopt_pocsprof option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_sflag(sflag);
    option.set_eflag(eflag);

    header_len += TCPOPT_POCSPROF_LEN;
    packet_len += TCPOPT_POCSPROF_LEN;
}


void c_tcp_packet::add_opt_cc(dword segment)
{
    c_tcpopt_cc option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_segment(segment);

    header_len += TCPOPT_CC_LEN;
    packet_len += TCPOPT_CC_LEN;
}


void c_tcp_packet::add_opt_ccnew(dword segment)
{
    c_tcpopt_ccnew option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_segment(segment);

    header_len += TCPOPT_CCNEW_LEN;
    packet_len += TCPOPT_CCNEW_LEN;
}


void c_tcp_packet::add_opt_ccecho(dword segment)
{
    c_tcpopt_ccecho option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_segment(segment);

    header_len += TCPOPT_CCNEW_LEN;
    packet_len += TCPOPT_CCNEW_LEN;
}


void c_tcp_packet::add_opt_altcsr(word cksum)
{
    c_tcpopt_altcsr option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_cksum(cksum);

    header_len += TCPOPT_ALTCSR_LEN;
    packet_len += TCPOPT_ALTCSR_LEN;
}


void c_tcp_packet::add_opt_altcsd(byte* data, u_int data_len)
{
    c_tcpopt_altcsd option(packet + header_len);

    option.set_code();
    option.set_len(TCPOPT_ALTCSD_LEN + data_len);

    header_len += TCPOPT_ALTCSD_LEN + data_len;
    packet_len += TCPOPT_ALTCSD_LEN + data_len;
}


void c_tcp_packet::add_opt_signature(string* signature)
{
    c_tcpopt_signature option(packet + header_len);

    option.set_code();
    option.set_len();
    option.set_signature(signature);

    header_len += TCPOPT_SIGNATURE_LEN;
    packet_len += TCPOPT_SIGNATURE_LEN;
}


void c_tcp_packet::add_opt_generic(byte type, byte* data, u_int data_len)
{
    c_tcpopt_generic option(packet + header_len);

    option.set_code(type);
    option.set_len(TCPOPT_GENERIC_LEN + data_len);
    option.set_data(data, data_len);

    header_len += TCPOPT_GENERIC_LEN + data_len;
    packet_len += TCPOPT_GENERIC_LEN + data_len;
}


