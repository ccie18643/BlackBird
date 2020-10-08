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


#ifndef _NETZ_IP_ADVSUPP_H_
#define _NETZ_IP_ADVSUPP_H_

#include "ip_support.h"


class c_tcp_packet;
class c_udp_packet;
class c_icmp_packet;


class c_ip_packet
{
protected:

    byte packet[1024 * 64];

    u_int header_len;
    u_int packet_len;


public:

    byte* get_packet() { return packet; }
    u_int get_packet_len() { return packet_len; }


public:

    c_ip_packet(dword, dword, word = 0, byte = 64, byte = 0, byte = 0);
    c_ip_packet(char*, char*, word = 0, byte = 64, byte = 0, byte = 0);

    void add_opt_eol();
    void add_opt_nop(u_int = 1);
    void add_opt_rr(dword*, u_int); 
    void add_opt_timestamp(byte, byte, dword*, u_int);
    void add_opt_sec(byte, byte*, u_int);
    void add_opt_xsec(byte asiac, byte*, u_int);
    void add_opt_lsrr(dword*, u_int);  
    void add_opt_ssrr(dword*, u_int);  
    void add_opt_satid(word);
    void add_opt_pmtu(word);   
    void add_opt_rmtu(word);   
    void add_opt_generic(byte type, byte*, u_int);

    void add_data(byte*, u_int);
    void add_data(c_tcp_packet);
    void add_data(c_udp_packet);
    void add_data(c_icmp_packet);
    void add_data(c_ip_packet);

    void verify();

    int send();
};

#endif /* _NETZ_IP_ADVSUPP_H_ */
