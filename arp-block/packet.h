#ifndef PACKET_H_
#define PACKET_H_

// C++
#include <iostream>

// libpcap
#include <pcap.h>

#include "arphdr.h"
#include "ethhdr.h"

#pragma pack(push, 1)

struct TxArpPacket {
    struct EthHdr ethhdr;
    struct ArpHdr arphdr;
};

struct RxPacket {
    pcap_t *handle;
    struct pcap_pkthdr *header;
    const uint8_t *bytes;

    struct EthHdr *ethhdr{nullptr};
    struct ArpHdr *arphdr{nullptr};

    void clear() {
        ethhdr = nullptr;
        arphdr = nullptr;
    }

    bool capture() { return pcap_next_ex(handle, &header, &bytes); }
    uint32_t len() { return (uint32_t)header->caplen; }

    bool openPcap(const char *);
    void parse();
    bool sendPkt(TxArpPacket *);
};

#pragma pack(pop)

#endif // PACKET_H_