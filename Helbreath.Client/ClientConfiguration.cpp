#include "ClientConfiguration.h"



char * ClientConfiguration::GetIPAddress()
{
	if (USE_DNS) {
		return GetIPAddressFromDNS(DNS_NAME);
	}
	else {
		return SERVER_IP;
	}
}

ClientConfiguration::ClientConfiguration()
{
}


ClientConfiguration::~ClientConfiguration()
{
}

char * ClientConfiguration::GetIPAddressFromDNS(char * dnsName)
{
	WSADATA wsaData;
	char *ipAddress;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		return "";
	}
	else {
		auto hostname = gethostbyname(dnsName);
		ipAddress = inet_ntoa(*((struct in_addr *) hostname->h_addr_list[0]));
	}
	return ipAddress;
}
