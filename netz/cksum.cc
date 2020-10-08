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


#include "cksum.h"


word cksum(byte* data, u_int data_len)
{
    dword cksum = 0;

    while(data_len > 1)
    {
	cksum += *((word*)data);

	if(cksum & 0x80000000)
	{
	    cksum = (cksum & 0xFFFF) + (cksum >> 16);
	}
	
        data += 2;
	data_len -= 2;
    }

    if (data_len)
    {
	cksum += (word) *(byte*) data;
    }

    while (cksum >> 16)
    {
	cksum = (cksum & 0xFFFF) + (cksum >> 16);
    }
    
    return ~cksum;
}


word cksum(byte* data, u_int data_len, c_pseudo_header pseudo_header)
{
    dword cksum = 0;

    byte* pheader = pseudo_header.header;
    u_int pheader_len = pseudo_header.header_len;

    while(pheader_len)
    {
        cksum += *((word*)pheader);

        if(cksum & 0x80000000)
        {
            cksum = (cksum & 0xFFFF) + (cksum >> 16);
	}
	
        pheader += 2;
	pheader_len -= 2;
    }

    while(data_len > 1)
    {
	cksum += *((word*)data);

	if(cksum & 0x80000000)
	{
	    cksum = (cksum & 0xFFFF) + (cksum >> 16);
	}
	
        data += 2;
	data_len -= 2;
    }

    if (data_len)
    {
	cksum += (word) *(byte*) data;
    }

    while (cksum >> 16)
    {
	cksum = (cksum & 0xFFFF) + (cksum >> 16);
    }
    
    return ~cksum;
}

