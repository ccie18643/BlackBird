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

string help_string[] = "\n"
"usage:\n"
"\n"
"bbird -i{interface} [-p] [-c] [-F{f_file}] [filter string]\n"
"\n"
"bbird -h\n"
"\n"
"\n"
"examples:\n"
"\n"
"bbird -itun0 -Ffilter1\n"
"\n"
"\n"
"options:\n"
"\n"
" -H  Hide specific frame/packet/datagram types\n"
"     el   - ethernet loopback\n"
"     cdp  - cisco discovery protocol\n"
"\n"
" -c  Count of first bytes that have to be catured for each packet\n"
"\n"
" -o  Output to file, filename given as parametr\n"
"\n"
" -O  Output to file only, no screen output, filename given as parametr\n"
"\n"
" -i  Interface, currently ethernet, tun and loopback are supported\n"
"\n"
" -p  Promisious mode off\n"
"\n"
" -F  Filter file, reads filter rule from given file\n"
"\n"
" -h  Displays this message ;)\n"
"\n\n";
