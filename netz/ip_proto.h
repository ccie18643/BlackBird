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


#ifndef _NETZ_IP_PROTO_H_
#define _NETZ_IP_PROTO_H_


/*
 * Definitions of protocols that can be encapsluated in IP or IPv6 packet
 */

#define IP_PROTO_HOPOPTS        0x00	/* hop-by-hop option header */
#define IP_PROTO_ICMP           0x01	/* control message protocol */
#define IP_PROTO_IGMP           0x02	/* group mgmt protocol */
#define IP_PROTO_GGP            0x03	/* gateway (deprecated) */
#define IP_PROTO_IPV4           0x04	/* IP */
#define IP_PROTO_TCP            0x06	/* tcp */
#define IP_PROTO_EGP            0x08	/* exterior gateway protocol */
#define IP_PROTO_IGRP           0x09	/* Cisco IGRP routing protocol */
#define IP_PROTO_PUP            0x0C	/* pup */
#define IP_PROTO_UDP            0x11	/* user datagram protocol */
#define IP_PROTO_IDP            0x16	/* xns idp */
#define IP_PROTO_TP             0x1D	/* tp-4 w/ class negotiation */
#define IP_PROTO_IPV6           0x29 	/* IPv6 */
#define IP_PROTO_ROUTING        0x2B 	/* routing header */
#define IP_PROTO_FRAGMENT       0x2C	/* fragmentation/reassembly header */
#define IP_PROTO_RSVP           0x2E	/* resource reservation */
#define IP_PROTO_GRE            0x2F	/* GRE encap (RFCs 1701/1702) */
#define IP_PROTO_ESP            0x32	/* encap. security payload */
#define IP_PROTO_AH             0x33	/* authentication header */
#define IP_PROTO_MOBILE         0x37 	/* IP mobility (RFC 2004) */
#define IP_PROTO_ICMPV6         0x3A	/* ICMP for IPv6 */
#define IP_PROTO_NONE           0x3B	/* no next header */
#define IP_PROTO_DSTOPTS        0x3C	/* destination options header */
#define IP_PROTO_EON            0x50	/* ISO cnlp */
#define IP_PROTO_EIGRP          0x58	/* Cisco EIGRP routing protocol */
#define IP_PROTO_OSPF           0x59	/* OSPF routing protocol */
#define IP_PROTO_ETHERIP        0x61	/* ethernet */
#define IP_PROTO_ENCAP          0x62	/* encapsulation header */
#define IP_PROTO_PIM            0x67	/* protocol indep. multicast */
#define IP_PROTO_IPCOMP         0x6C	/* IP payload comp. protocol */
#define IP_PROTO_RAW            0xFF	/* raw IP packet */


#endif /* _NETZ_IP_PROTO_H_ */
