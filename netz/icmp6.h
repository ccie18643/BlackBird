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


#ifndef _NETZ_ICMP6_H_
#define _NETZ_ICMP6_H_


#include "types.h"


struct s_icmp6_header
{
    byte  type;
    byte  code;
    word  cksum;
};


#define ICMP6_HEADER_LEN sizeof(s_icmp6_header)


struct s_icmp6_pkttoobig
{
    dword mtu;
};


struct s_icmp6_paramprob
{
    dword pointer;
};


struct s_icmp6_echorequest
{
    word id;
    word seqnumber;
};


struct s_icmp6_echoreply
{
     word id;
     word seqnumber;
};


struct s_icmp6_routeradvert
{
     byte hoplimit;
     byte flags;
     word lifetime;
     dword reachabletime;
     dword retranstimer;
     /* OPTIONS (variable length) */
};

#define ICMP6_ROUTER_ADVERTISEMENT_FLAG_OSC_MASK     0x40
#define ICMP6_ROUTER_ADVERTISEMENT_FLAG_MAC_MASK     0x80


struct s_icmp6_routersolicit
{
     dword unused;
     /* OPTIONS (variable length) */
}; 


struct s_icmp6_nbsolicit
{
     dword unused;
     byte target[16];
     /* OPTIONS (variable length) */
};


struct s_icmp6_nbadvert
{
     byte flags;
     byte unused[3];
     byte target[16];
     /* OPTIONS (variable length) */
}; 

#define ICMP6_NEIGHBOR_ADVERTISEMENT_FLAG_OVERRIDE_MASK   0x20
#define ICMP6_NEIGHBOR_ADVERTISEMENT_FLAG_SOLICITED_MASK  0x40
#define ICMP6_NEIGHBOR_ADVERTISEMENT_FLAG_ROUTER_MASK     0x80


struct s_icmp6_redirect
{
     dword unused;
     byte target[16];
     byte dst[16];
     /* OPTIONS (variable length) */
};


struct s_icmp6_routerrenum
{
     dword seqnumber;
     byte segnumber;
     byte flags;
     word maxdelay;
     dword unused;
     /* RR BODY (variable length) */
};



#define ICMP6_UNREACH                      1 /* dest unreachable (RFC 2463) */
#define     ICMP6_UNREACH_NOROUTE          0 /* no route to destination */
#define     ICMP6_UNREACH_DSTPROHIB        1 /* communication with destination
                                                administratively prohibited */
#define     ICMP6_UNREACH_NOTNEIGHBOR      2 /* not a neighbor */       
#define     ICMP6_UNREACH_BADADDR          3 /* bad address */
#define     ICMP6_UNREACH_BADPORT          4 /* bad port */

#define ICMP6_PACKET_TOO_BIG               2 /* packet is larger than the MTU of
                                                the outgoing link (RFC 2463) */
#define ICMP6_TIMEXCEED	                   3 /* time of life
                                                exceded (RFC 2463) */
#define     ICMP6_TIMEXCEED_TRANSIT    	   0 /* hop limit exceeded in transit */
#define     ICMP6_TIMEXCEED_REASSEMBLY 	   1 /* fragment reassembly time
                                                exceeded */
#define ICMP6_PARAMPROB	                   4 /* parameter problem (RFC 2463) */
#define     ICMP6_PARAMPROB_HEADER         0 /* erroneous header field */
#define     ICMP6_PARAMPROB_NEXTHEADER     1 /* unrecognized next header type */
#define     ICMP6_PARAMPROB_OPTION         2 /* unrecognized IPv6 option */

#define ICMP6_ECHO_REQUEST               128 /* echo request (RFC 2463) */

#define ICMP6_ECHO_REPLY                 129 /* echo reply (RFC 2463) */

#define ICMP6_MEMBERSHIP_QUERY           130 /* membership query */ 

#define ICMP6_MEMBERSHIP_REPORT          131 /* membership report */

#define ICMP6_MEMBERSHIP_REDUCTION       132 /* membership reduction */

#define ICMP6_ROUTER_SOLICITATION        133 /* router solicitation
                                                (RFC 2461) */
#define ICMP6_ROUTER_ADVERTISEMENT       134 /* router advertisement
                                                (RFC 2461) */
#define ICMP6_NEIGHBOR_SOLICITATION      135 /* neighbor
                                                solicitation (RFC 2461) */
#define ICMP6_NEIGHBOR_ADVERTISEMENT     136 /* neighbor
                                                advertisement (RFC 2461) */
#define ICMP6_REDIRECT                   137 /* redirect (RFC 2461) */

#define ICMP6_ROUTER_RENUM               138 /* router renumbering (RFC 2894) */
#define     ICMP6_ROUTER_RENUM_COMMAND     0 /* router renumbering command */
#define     ICMP6_ROUTER_RENUM_RESULT      1 /* router renumbering result */
#define     ICMP6_ROUTER_RENUM_SNRESET   255 /* sequence number reset */

#define ICMP6_NODE_INFORMATION_QUERRY    139 /* ICMP node information query */

#define ICMP6_NODE_INFORMATION_RESPONSE  140 /* ICMP node information
                                                response */

#define ICMP6_INV_NEIGHBOR_SOLICICATION  141 /* inverse neighbor discovery
                                                solicitation (RFC 3122) */
#define ICMP6_INV_NEIGHBOR_ADVERTISEMENT 142 /* inverse neighbor discovery
                                                advertisement (RFC 3122) */


#endif /* _NETZ_ICMP6_H_ */

