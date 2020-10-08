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


#ifndef _NETZ_ICMP6_SUPPORT_H_
#define _NETZ_ICMP6_SUPPORT_H_


#include "icmp6.h"
#include "support.h"


class c_icmp6_header
{
protected:
    s_icmp6_header* header;

public:
    c_icmp6_header(byte*);
    s_icmp6_header* get_header();

    byte get_type();
    byte get_code();
    word get_cksum();

    void set_type(byte);
    void set_code(byte);
    void set_cksum(word);
};


class c_icmp6_pkttoobig
{
protected:
    s_icmp6_pkttoobig* body;

public:
    c_icmp6_pkttoobig(c_icmp6_header);

    dword get_mtu();

    void set_mtu(dword);
};


class c_icmp6_paramprob
{
protected:
    s_icmp6_paramprob* body;

public:
    c_icmp6_paramprob(c_icmp6_header);

    dword get_pointer();

    void set_pointer(dword);
};


class c_icmp6_echorequest
{
protected:
    s_icmp6_echorequest* body;

public:
    c_icmp6_echorequest(c_icmp6_header);

    word get_id();
    word get_seqnumber();

    void set_id(word);
    void set_seqnumber(word);
};


class c_icmp6_echoreply
{
protected:
     s_icmp6_echoreply* body;

public:
     c_icmp6_echoreply(c_icmp6_header);

     word get_id();
     word get_seqnumber();

     void set_id(word);
     void set_seqnumber(word);
};


class c_icmp6_routeradvert
{
protected:
     s_icmp6_routeradvert* body;

public:
     c_icmp6_routeradvert(c_icmp6_header);

     byte get_hoplimit();
     byte get_flags();
     byte get_flag_mac();
     byte get_flag_osc();
     word get_lifetime();
     dword get_reachtimer();
     dword get_retrtimer();

     void set_hoplimit(byte);
     void set_flags(byte);
     void set_flag_mac(byte = 1);
     void set_flag_osc(byte = 1);
     void set_lifetime(word);
     void set_reachtimer(dword);
     void set_retrtimer(dword);
};


class c_icmp6_nbsolicit
{
protected:
     s_icmp6_nbsolicit* body;

public: 
     c_icmp6_nbsolicit(c_icmp6_header);

     byte get_target(u_int);
     byte* get_target();

     void set_target(u_int, byte);
     void set_target(byte*);
};


class c_icmp6_nbadvert
{
protected:
     s_icmp6_nbadvert* body;

public:
     c_icmp6_nbadvert(c_icmp6_header);

     byte get_flags();
     byte get_flag_router();
     byte get_flag_solicited();
     byte get_flag_override();
     byte get_target(u_int);
     byte* get_target();

     void set_flags(byte);
     void set_flag_router(byte = 1);
     void set_flag_solicited(byte = 1);
     void set_flag_override(byte = 1);
     void set_target(u_int, byte);
     void set_target(byte*);
}; 


class c_icmp6_redirect
{
protected:
     s_icmp6_redirect* body;

public:
     c_icmp6_redirect(c_icmp6_header);

     byte get_target(u_int);
     byte* get_target();
     byte get_dst(u_int);
     byte* get_dst();

     void set_target(u_int, byte);
     void set_target(byte*);
     void set_dst(u_int, byte);
     void set_dst(byte*);
};


class c_icmp6_routerrenum
{
protected:
     s_icmp6_routerrenum* body;

public:
     c_icmp6_routerrenum(c_icmp6_header);

     dword get_seqnumber();
     byte get_segnumber();
     byte get_flags();
     word get_maxdelay();

     void set_seqnumber(dword);
     void set_segnumber(byte);
     void set_flags(byte);
     void set_maxdelay(word);
};


#endif /* _NETZ_ICMP6_SUPPORT_H_ */

