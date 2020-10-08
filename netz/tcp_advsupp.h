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


#ifndef _NETZ_TCP_ADVSUPP_H_
#define _NETZ_TCP_ADVSUPP_H_

#include "tcp_support.h"

struct c_pseudo_header;


class c_tcp_packet
{

protected:

    byte packet[64 * 1024];

    u_int header_len;
    u_int packet_len;


public:

    byte* get_packet() { return packet; }
    u_int get_packet_len() { return packet_len; }
   
public:

    c_tcp_packet(word sport, word dport, dword seq = 0, dword ack = 0,
                 byte flags = 0, word win = 0, word urp = 0);

    void add_opt_eol();

    void add_opt_nop(u_int = 1);

    void add_opt_mss(word = 536);

    void add_opt_wscale(byte);

    void add_opt_sackperm();

    void add_opt_sack(dword*, u_int);

    void add_opt_echo(dword);

    void add_opt_echoreply(dword);

    void add_opt_timestamp(dword, dword);

    void add_opt_pocperm();

    void add_opt_pocsprof(byte, byte);

    void add_opt_cc(dword);

    void add_opt_ccnew(dword); 

    void add_opt_ccecho(dword); 

    void add_opt_altcsr(word);

    void add_opt_altcsd(byte*, u_int);

    void add_opt_signature(string*);

    void add_opt_generic(byte, byte*, u_int);

    void add_data(byte* data, u_int data_len);

    void verify();

    void verify(c_pseudo_header);
};

#endif /* _NETZ_TCP_ADVSUPP_H_ */
