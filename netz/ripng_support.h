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


#ifndef _NETZ_RIPNG_SUPPORT_H_
#define _NETZ_RIPNG_SUPPORT_H_


#include "ripng.h"

/*
 * RIPng protocol support class.
 */


class c_ripng_header {

protected:
    s_ripng_header* header;


public:
    c_ripng_header(byte*);
    c_ripng_header(s_ripng_header*);

    byte get_cmd();
    byte get_ver();
};



/*
 * RIPng route entry support class.
 */


class c_ripng_route_entry {

protected:
    s_ripng_route_entry* route_entry;

public:
    c_ripng_route_entry(byte*);
    c_ripng_route_entry(s_ripng_route_entry*);

    byte* get_prefix();
    word get_tag();
    byte get_prefix_len();
    byte get_metric();
};


/*
 * RIPng next hop entry support class.
 */


class c_ripng_next_hop_entry {

protected:
    s_ripng_next_hop_entry* next_hop_entry;

public:
    c_ripng_next_hop_entry(byte*);
    c_ripng_next_hop_entry(s_ripng_next_hop_entry*);

    byte* get_next_hop();
};

#endif /* _NETZ_RIPNG_SUPPORT_H_ */

