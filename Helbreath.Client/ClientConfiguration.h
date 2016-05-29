#pragma once

#include "GlobalDef.h"
#include <WinSock2.h>

class ClientConfiguration
{
public:
	char* GetIPAddress();
	int GetPort();
	ClientConfiguration();
	~ClientConfiguration();
private:
	char* GetIPAddressFromDNS(char *dnsName);
};

