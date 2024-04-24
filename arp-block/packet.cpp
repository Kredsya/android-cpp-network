#include "packet.h"

bool RxPacket::openPcap(const char *interface) {
    char errbuf[PCAP_ERRBUF_SIZE];
    handle = pcap_open_live(interface, BUFSIZ, 1, -1, errbuf);
    if (handle == NULL) {
        std::cerr << "pcap_open_live(" << interface << ") return null\n"
                  << errbuf << '\n';
        return false;
    }
    return true;
}

void RxPacket::parse() {
    ethhdr = (struct EthHdr *)(bytes);
    switch (ethhdr->type()) {
    case EthHdr::arp:
        arphdr = (struct ArpHdr *)(bytes + ETH_SIZE);
        break;
    }
}

bool RxPacket::sendPkt(TxArpPacket *packet) {
    int res = pcap_sendpacket(handle, reinterpret_cast<const u_char *>(packet), sizeof(TxArpPacket));
    if (res) {
        std::cerr << "pcap_sendpacket return " << res << '\n';
        std::cerr << pcap_geterr(handle) << '\n';
        return false;
    }
    return true;
}