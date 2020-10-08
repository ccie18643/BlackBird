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


#ifndef _NETZ_IGRP_SUPPORT_H_
#define _NETZ_IGRP_SUPPORT_H_


#include "igrp.h"

/*
 * IGRP protocol support class.
 */

class c_igrp_header {

protected:
    s_igrp_header* header;

public:
    c_igrp_header(byte*);
    c_igrp_header(s_igrp_header*);

    byte get_ver();
    byte get_opcode();
    byte get_edition();
    word get_as();
    word get_interior();
    word get_system();
    word get_exterior();
    word get_cksum();

    void set_ver(byte);
    void set_opcode(byte);
    void set_edition(byte);
    void set_as(word);
    void set_interior(word);
    void set_system(word);
    void set_exterior(word);
    void set_cksum(word = 0);
};


class c_igrp_update {

protected:
    s_igrp_update* update;

public:
    c_igrp_update(byte*);
    c_igrp_update(s_igrp_update*);
 
    dword get_net();
    dword get_intnet();
    dword get_delay();
    dword get_bandwidth();
    word get_mtu();
    byte get_reliability();
    byte get_load();
    byte get_hopcount();

    void set_net(dword);
    void set_intnet(dword);
    void set_delay(dword);
    void set_bandwidth(dword);
    void set_mtu(word);
    void set_reliability(byte);
    void set_load(byte);
    void set_hopcount(byte);
};

#endif /* _NETZ_IGRP_SUPPORT_H_ */

