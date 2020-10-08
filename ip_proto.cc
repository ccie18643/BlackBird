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


#include <netz.h>

#include "ip_proto.h"
#include "support.h"


c_string print_ip_proto(byte proto)
{
    switch(proto)
    {
        case IP_PROTO_TCP:
            return c_string("TCP");

        case IP_PROTO_UDP:
            return c_string("UDP");

        case IP_PROTO_ICMP:
            return c_string("ICMP");

        case IP_PROTO_IGMP:
            return c_string("IGMP");

        case IP_PROTO_IPV4:
            return c_string("IPv4");

        case IP_PROTO_EGP:
            return c_string("EGP");

        case IP_PROTO_IGRP:
            return c_string("IGRP");

        case IP_PROTO_PUP:
            return c_string("PUP");

        case IP_PROTO_IDP:
            return c_string("IDP");

        case IP_PROTO_TP:
            return c_string("TP");

        case IP_PROTO_IPV6:
            return c_string("IPv6");

        case IP_PROTO_ROUTING:
            return c_string("Routing header");

        case IP_PROTO_FRAGMENT:
            return c_string("Fragment header");

        case IP_PROTO_RSVP:
            return c_string("RSVP");

        case IP_PROTO_GRE:
            return c_string("GRE");

        case IP_PROTO_ESP:
            return c_string("ESP");

        case IP_PROTO_AH:
            return c_string("AH");

        case IP_PROTO_MOBILE:
            return c_string("Mobile header");

        case IP_PROTO_ICMPV6:
            return c_string("ICMPv6");

        case IP_PROTO_NONE:
            return c_string("None");

        case IP_PROTO_DSTOPTS:
            return c_string("DSTOPTS");

        case IP_PROTO_EON:
            return c_string("EON");

        case IP_PROTO_EIGRP:
            return c_string("EIGRP");

        case IP_PROTO_OSPF:
            return c_string("OSPF");

        case IP_PROTO_ETHERIP:
            return c_string("Ethernet over IP");

        case IP_PROTO_ENCAP:
            return c_string("ENCAP");

        case IP_PROTO_PIM:
            return c_string("PIM");

        case IP_PROTO_IPCOMP:
            return c_string("IPCOMP");

        case IP_PROTO_RAW:
            return c_string("RAW");

	default:
            return c_string("Unknown");
    }
}


