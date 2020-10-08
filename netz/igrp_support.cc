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


#include "igrp_support.h"
#include "support.h"

c_igrp_header::c_igrp_header(byte* igrp_header)
{
    header = (s_igrp_header*)igrp_header;
}


c_igrp_header::c_igrp_header(s_igrp_header* igrp_header)
{
    header = igrp_header;
}


byte c_igrp_header::get_ver()
{
    return bits(ntoh(header->vo), IGRP_VO_VER_MASK);
}


void c_igrp_header::set_ver(byte ver)
{
    header->vo = hton(bits(ntoh(header->vo), IGRP_VO_VER_MASK, ver));
}


byte c_igrp_header::get_opcode()
{
    return bits(ntoh(header->vo), IGRP_VO_OPCODE_MASK);
}


void c_igrp_header::set_opcode(byte opcode)
{
    header->vo = hton(bits(ntoh(header->vo), IGRP_VO_OPCODE_MASK, opcode));
}


byte c_igrp_header::get_edition()
{
    return ntoh(header->edition);
}


void c_igrp_header::set_edition(byte edition)
{
    header->edition = hton(edition);    
}


word c_igrp_header::get_as()
{
    return ntoh(header->as);
}


void c_igrp_header::set_as(word as)
{
    header->as = hton(as);    
}


word c_igrp_header::get_interior()
{
    return ntoh(header->interior);
}


void c_igrp_header::set_interior(word interior)
{
    header->interior = hton(interior);    
}


word c_igrp_header::get_system()
{
    return ntoh(header->system);
}


void c_igrp_header::set_system(word system)
{
    header->system = hton(system);    
}


word c_igrp_header::get_exterior()
{
    return ntoh(header->exterior);
}


void c_igrp_header::set_exterior(word exterior)
{
    header->exterior = hton(exterior);
}


word c_igrp_header::get_cksum()
{
    return ntoh(header->cksum);
}


void c_igrp_header::set_cksum(word cksum)
{
    header->cksum = hton(cksum);
}




c_igrp_update::c_igrp_update(byte* igrp_update)
{
    update = (s_igrp_update*)igrp_update;
}


c_igrp_update::c_igrp_update(s_igrp_update* igrp_update)
{
    update = igrp_update;
}


dword c_igrp_update::get_net()
{
    dword net;

    *((byte*)&net + 3) = ntoh(update->number[0]);
    *((byte*)&net + 2) = ntoh(update->number[1]);
    *((byte*)&net + 1) = ntoh(update->number[2]);
    *((byte*)&net + 0) = 0;

    return ntoh(net);
}


dword c_igrp_update::get_intnet()
{
    dword net;

    *((byte*)&net + 3) = 0;
    *((byte*)&net + 2) = ntoh(update->number[0]);
    *((byte*)&net + 1) = ntoh(update->number[1]);
    *((byte*)&net + 0) = ntoh(update->number[2]);

    return ntoh(net);
}


dword c_igrp_update::get_delay()
{
    dword delay;

    *((byte*)&delay + 0) = 0;
    *((byte*)&delay + 1) = ntoh(update->delay[0]);
    *((byte*)&delay + 2) = ntoh(update->delay[1]);
    *((byte*)&delay + 3) = ntoh(update->delay[2]);

    return ntoh(delay);
}


dword c_igrp_update::get_bandwidth()
{
    dword bandwidth;

    *((byte*)&bandwidth + 0) = 0;
    *((byte*)&bandwidth + 1) = ntoh(update->bandwidth[0]);
    *((byte*)&bandwidth + 2) = ntoh(update->bandwidth[1]);
    *((byte*)&bandwidth + 3) = ntoh(update->bandwidth[2]);

    return ntoh(bandwidth);
}


word c_igrp_update::get_mtu()
{
    return ntoh(update->mtu);
}

byte c_igrp_update::get_reliability()
{
    return ntoh(update->reliability);
}

byte c_igrp_update::get_load()
{
    return ntoh(update->load);
}

byte c_igrp_update::get_hopcount()
{
    return ntoh(update->hopcount);
}



