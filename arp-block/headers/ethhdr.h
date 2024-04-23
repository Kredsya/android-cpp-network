#ifndef ETHHDR_H_
#define ETHHDR_H_

#include "hpch.h"

#define ETH_SIZE 14

#pragma pack(push, 1)
struct EthHdr {
    uint8_t dst_[6];
    uint8_t src_[6];
    uint16_t type_;

    uint8_t *dst() { return dst_; }
    uint8_t *src() { return src_; }
    uint16_t type() { return ntohs(type_); }

    void parseDst(std::string str) { sscanf(str.c_str(), "%x:%x:%x:%x:%x:%x", &dst_[0], &dst_[1], &dst_[2], &dst_[3], &dst_[4], &dst_[5]); };
    void parseSrc(std::string str) { sscanf(str.c_str(), "%x:%x:%x:%x:%x:%x", &src_[0], &src_[1], &src_[2], &src_[3], &src_[4], &src_[5]); };

    enum : uint16_t {
        arp = 0x0806,
        ipv4 = 0x0800
    };
};
#pragma pack(pop)

#endif // ETHHDR_H_
