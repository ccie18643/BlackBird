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


#ifndef _NETZ_ARP_SUPPORT_H_
#define _NETZ_ARP_SUPPORT_H_


#include "arp.h"


class c_arp_header
{
protected:
    s_arp_header* header;
    byte* sha;
    byte* spa;
    byte* tha;
    byte* tpa;

public:
    c_arp_header(byte*);
    c_arp_header(s_arp_header*);

    word get_hrtype();
    word get_prtype();
    byte get_hrlen();
    byte get_prlen();
    word get_operation();
    byte* get_sha();
    byte* get_spa();
    byte* get_tha();
    byte* get_tpa();

    void set_hrtype(word = 4);
    void set_prtype(word = 4);
    void set_hrlen(byte = 6);
    void set_prlen(byte = 6);
    void set_operation(word);
    void set_sha(byte*, u_int = 0);
    void set_spa(byte*, u_int = 0);
    void set_tha(byte*, u_int = 0);
    void set_tpa(byte*, u_int = 0);
};

#endif /* _NETZ_ARP_SUPPORT_H_ */
