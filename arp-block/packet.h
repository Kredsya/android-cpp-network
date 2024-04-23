#ifndef PACKET_H_
#define PACKET_H_

#include "pch.h"

#include "headers/arphdr.h"
#include "headers/ethhdr.h"

#pragma pack(push, 1)

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

struct TxArpPacket {
    struct EthHdr ethhdr;
    struct ArpHdr arphdr;
};

#pragma pack(pop)

#endif // PACKET_H_