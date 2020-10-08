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


#include <sys/types.h>
#include <unistd.h>
#include <pcap.h>

#include "raw8023_advsupp.h"
#include "ip_advsupp.h"


c_raw8023_packet::c_raw8023_packet(byte* src, byte* dst, word dlen)
{
    c_raw8023_header header(packet);

    header.set_src(src);
    header.set_dst(dst); 
    header.set_dlen(dlen);

    header_len = RAW8023_HEADER_LEN;
    packet_len = header_len;    
}


void c_raw8023_packet::verify()
{
    c_raw8023_header header(packet);

    header.set_dlen(packet_len - header_len);
}


int c_raw8023_packet::send(string* interface)
{
    verify();

    string errbuf[PCAP_ERRBUF_SIZE];
    
    pcap_t* pcap = pcap_open_live(interface, 0, 0, 0, errbuf);

    if(!pcap)
    {
        return -1;
    }

    int retval = write(*((int*)pcap), packet, packet_len);

    pcap_close(pcap);

    return retval;
}


int c_raw8023_packet::send(pcap_t* pcap)
{
    return write(*((int*)pcap), packet, packet_len);
}

