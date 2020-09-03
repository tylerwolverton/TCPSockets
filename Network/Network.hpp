#pragma once
#include <iostream>
#include <string>
#include <array>
#include <winsock2.h>
#include <ws2tcpip.h>

class Network
{
public:
	void Startup();
	void Shutdown();
};
