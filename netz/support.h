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


#ifndef _NETZ_SUPPORT_H_
#define _NETZ_SUPPORT_H_


#include "types.h"

void message(string*, ...);

byte hton(byte);
byte ntoh(byte);

word hton(word);
word ntoh(word);

dword hton(dword);
dword ntoh(dword);

byte rotation(dword);

byte bits(byte, byte);
word bits(word, word);
word bits(dword, dword);
byte bits(byte, byte, byte);
word bits(word, word, byte);
word bits(word, word, word);
dword bits(dword, dword, byte);
dword bits(dword, dword, word);
dword bits(dword, dword, dword);


string* conv_ip_str(string*, dword);
string* conv_ip_str(string*, byte*);
string* conv_ip6_str(string*, byte*);
string* conv_ether_str(string*, byte*);
string* conv_ipx_str(string*, byte*);
string* conv_ieee8023_str(string*, byte*);
string* conv_raw8023_str(string*, byte*);

dword conv_str_ip(string*);

int cmp_ether_str(string*, string*);

#endif /* _NETZ_SUPPORT_H_ */

