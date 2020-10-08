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

#include "ether_type.h"
#include "support.h"


c_string print_ether_type(word type)
{
    switch(type)
    {
        case ETHER_TYPE_IDP:
            return c_string("IDP");

	case ETHER_TYPE_IP:
            return c_string("IPv4");

        case ETHER_TYPE_X75:
            return c_string("X.75");

        case ETHER_TYPE_NBS:
            return c_string("NBS");

        case ETHER_TYPE_ECMA:
            return c_string("ECMA"); 

        case ETHER_TYPE_CHAOS:
            return c_string("Chaos");

        case ETHER_TYPE_X25:
            return c_string("X.25");

	case ETHER_TYPE_ARP:
            return c_string("ARP");

        case ETHER_TYPE_XNS:
            return c_string("XNS");

        case ETHER_TYPE_XPUP:
            return c_string("XPUP");

        case ETHER_TYPE_DECNET:
            return c_string("DecNet");

        case ETHER_TYPE_EXCELAN:
            return c_string("ExceLan");

        case ETHER_TYPE_SGI:
            return c_string("SGI");

	case ETHER_TYPE_REVARP:
            return c_string("RevARP");

        case ETHER_TYPE_UM:
            return c_string("UM");

        case ETHER_TYPE_ATT:
            return c_string("ATT");

        case ETHER_TYPE_APPLETALK:
            return c_string("AppleTalk");

        case ETHER_TYPE_BANYAN_80C4:
            return c_string("Banyan");

        case ETHER_TYPE_BANYAN_80C5:
            return c_string("Banyan");

        case ETHER_TYPE_IBMSNA:
            return c_string("IBM SNA");

        case ETHER_TYPE_AARP:
            return c_string("AARP");

        case ETHER_TYPE_APOLLO:
            return c_string("Apollo");

        case ETHER_TYPE_BRIDGE_8132:
            return c_string("Bridge");

        case ETHER_TYPE_BRIDGE_8133:
            return c_string("Bridge");

        case ETHER_TYPE_BRIDGE_8134:
            return c_string("Bridge");

        case ETHER_TYPE_BRIDGE_8135:
            return c_string("Bridge");

        case ETHER_TYPE_BRIDGE_8136:
            return c_string("Bridge");

        case ETHER_TYPE_IPX:
            return c_string("IPX");

        case ETHER_TYPE_NOVELL_8138:
            return c_string("Novell");

        case ETHER_TYPE_SNMP:
            return c_string("SNMP");

        case ETHER_TYPE_ASCOM:
            return c_string("Ascom");

        case ETHER_TYPE_AES_823E:
            return c_string("AES");

        case ETHER_TYPE_AES_823F:
            return c_string("AES");

        case ETHER_TYPE_AES_8240:
            return c_string("AES");

	case ETHER_TYPE_IP6:
            return c_string("IPv6");

	case ETHER_TYPE_PPPOEDISC:
            return c_string("PPPoE disc");

	case ETHER_TYPE_PPPOE:
            return c_string("PPPoE");

	case ETHER_TYPE_LOOPBACK:
            return c_string("Loopback");

        case ETHER_TYPE_BBN:
            return c_string("BBN");

        case SNAP_TYPE_CDP:
            return c_string("CDP");

	default:
            return c_string("Unknown");
    }
}

    
