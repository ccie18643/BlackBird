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


#ifndef _NETZ_OSPF_SUPPORT_H_
#define _NETZ_OSPF_SUPPORT_H_


#include "ospf.h"

/*
 * OSPF protocol support classes.
 */

class c_ospf_header {

protected:
    s_ospf_header* header;

    string password[9];

public:
    c_ospf_header(byte*);
    c_ospf_header(s_ospf_header*);

    byte get_ver();
    byte get_type();
    word get_plen();
    dword get_routerid();
    dword get_areaid();
    word get_cksum();
    word get_authtype();
    string* get_password();
    byte get_keyid();
    byte get_adlen();
    dword get_cryptoseq();
};


class c_ospf_lls {

protected:
    s_ospf_lls* lls;

public:
    c_ospf_lls(byte*);
    c_ospf_lls(s_ospf_lls*);

    word get_cksum();
    dword get_dlen();
};



class c_ospf_lls_tlv {

protected:
    s_ospf_lls_tlv* lls_tlv;

public:
    c_ospf_lls_tlv(byte*);
    c_ospf_lls_tlv(s_ospf_lls_tlv*);
  
    word get_type();
    word get_vlen();
};


class c_ospf_lls_tlv_extopt {

protected:
    s_ospf_lls_tlv_extopt* lls_tlv_extopt;

public:
    c_ospf_lls_tlv_extopt(byte*);
    c_ospf_lls_tlv_extopt(s_ospf_lls_tlv_extopt*);
  
    word get_type();
    word get_vlen();
    dword get_flags();
    byte get_flag_lr();
    byte get_flag_rs();
};


class c_ospf_lls_tlv_cauth {

protected:
    s_ospf_lls_tlv_cauth* lls_tlv_cauth;

public:
    c_ospf_lls_tlv_cauth(byte*);
    c_ospf_lls_tlv_cauth(s_ospf_lls_tlv_cauth*);
 
    word get_type();
    word get_vlen();
    dword get_cryptoseq();
    byte* get_authdata();
};


class c_ospf_hello_packet {
 
protected:
    s_ospf_hello_packet* hello_packet;
  
public:
    c_ospf_hello_packet(byte*);
    c_ospf_hello_packet(s_ospf_hello_packet*);
 
    dword get_netmask();
    word get_hellointerval();
    byte get_options();
    byte get_option_dc();
    byte get_option_l();
    byte get_option_np();
    byte get_option_mc();
    byte get_option_e();
    byte get_priority();
    dword get_deadinterval();
    dword get_dr();
    dword get_bdr();
    dword get_neighbor(u_int);
};



class c_ospf_dd_packet {

protected:
    s_ospf_dd_packet* dd_packet;

public:
    c_ospf_dd_packet(byte*);
    c_ospf_dd_packet(s_ospf_dd_packet*);

    word get_mtu();
    word get_options();
    byte get_option_ms();
    byte get_option_m();
    byte get_option_i();
    dword get_seq();
};



class c_ospf_lsr_packet {

protected:
    s_ospf_lsr_packet* lsr_packet;

public:
    c_ospf_lsr_packet(byte*);
    c_ospf_lsr_packet(s_ospf_lsr_packet*);

    dword get_type();
    dword get_id();
    dword get_advrtr();
};



class c_ospf_lsu_packet {

protected:
    s_ospf_lsu_packet* lsu_packet;

public:
    c_ospf_lsu_packet(byte*);
    c_ospf_lsu_packet(s_ospf_lsu_packet*);

    dword get_lcount();
};


class c_ospf_lsa_header {

protected:
    s_ospf_lsa_header* lsa_header;

public:
    c_ospf_lsa_header(byte*);
    c_ospf_lsa_header(s_ospf_lsa_header*);

    word get_age();
    byte get_options();
    byte get_option_dc();
    byte get_option_l();
    byte get_option_np();
    byte get_option_mc();
    byte get_option_e();
    byte get_type();
    dword get_id();
    dword get_advrtr();
    dword get_seq();
    word get_cksum();
    word get_len();
};


class c_ospf_lsa_1_body {

protected:
    s_ospf_lsa_1_body* lsa_1_body;

public:
    c_ospf_lsa_1_body(byte*);
    c_ospf_lsa_1_body(s_ospf_lsa_1_body*);

    byte get_flags();
    byte get_flag_nt();
    byte get_flag_w();
    byte get_flag_v();
    byte get_flag_e();
    byte get_flag_b();
    word get_lcount();
};


class c_ospf_lsa_1_link {

protected:
    s_ospf_lsa_1_link* lsa_1_link;

public:
    c_ospf_lsa_1_link(byte*);
    c_ospf_lsa_1_link(s_ospf_lsa_1_link*);

    dword get_id();
    dword get_data();
    byte get_type();
    byte get_tcount();
    word get_metric();
};


class c_ospf_lsa_1_link_tos {

protected:
    s_ospf_lsa_1_link_tos* lsa_1_link_tos;

public:
    c_ospf_lsa_1_link_tos(byte*);
    c_ospf_lsa_1_link_tos(s_ospf_lsa_1_link_tos*);

    byte get_tos();
    word get_metric();
};


class c_ospf_lsa_2_link {

protected:
    s_ospf_lsa_2_link* lsa_2_link;

public:
    c_ospf_lsa_2_link(byte*);
    c_ospf_lsa_2_link(s_ospf_lsa_2_link*);

    dword get_netmask();
    dword get_attrtr();
};


class c_ospf_lsa_3_body {

protected:
    s_ospf_lsa_3_body* lsa_3_body;

public:
    c_ospf_lsa_3_body(byte*);
    c_ospf_lsa_3_body(s_ospf_lsa_3_body*);

    dword get_netmask();
    dword get_metric();
};


class c_ospf_lsa_4_body {

protected:
    s_ospf_lsa_4_body* lsa_4_body;

public:
    c_ospf_lsa_4_body(byte*);
    c_ospf_lsa_4_body(s_ospf_lsa_4_body*);

    dword get_metric();
};


class c_ospf_lsa_5_body {

protected:
    s_ospf_lsa_5_body* lsa_5_body;

public:
    c_ospf_lsa_5_body(byte*);
    c_ospf_lsa_5_body(s_ospf_lsa_5_body*);

    dword get_netmask();      
    byte get_type();
    dword get_metric();      
    dword get_fwdaddr();      
    dword get_tag();
};


class c_ospf_lsa_7_body {

protected:
    s_ospf_lsa_7_body* lsa_7_body;

public:
    c_ospf_lsa_7_body(byte*);
    c_ospf_lsa_7_body(s_ospf_lsa_7_body*);

    dword get_netmask();
    byte get_type();
    dword get_metric();
    dword get_fwdaddr();
    dword get_tag();
};


#endif /* _NETZ_OSPF_SUPPORT_H_ */

