<<<<<<< HEAD
// Network.cpp : Defines the functions for the static library.
//

#include "Network.hpp"

#include "framework.h"
#include <exception>
#include <strstream>

//-----------------------------------------------------------------------------------------------
void Network::Startup()
{
	// Initalize winsock
	WSADATA wsaData;
	WORD wVersion = MAKEWORD( 2, 2 );
	int iResult = WSAStartup( wVersion, &wsaData );
	if ( iResult != 0 )
	{
		// Use Stringf in our engine
		std::ostrstream ostr;
		ostr << "Winsock startup failed, error: " << iResult << std::endl;
		throw std::runtime_error( ostr.str() );
	}
}


//-----------------------------------------------------------------------------------------------
void Network::Shutdown()
{
	int iResult = WSACleanup();
	if ( iResult == SOCKET_ERROR )
	{
		// Use Stringf in our engine
		std::ostrstream ostr;
		ostr << "Winsock cleanup failed, error: " << WSAGetLastError() << std::endl;
		throw std::runtime_error( ostr.str() );
	}
}


=======

#include <Network.h>
#include <exception>
#include <strstream>

void Network::initialize()
{
    // Initalize winsock
    WSADATA wsaData;
    WORD wVersion = MAKEWORD(2, 2);
    int iResult = WSAStartup(wVersion, &wsaData);
    if (iResult != 0)
    {
        std::ostrstream ostr;
        ostr << "Winsock startup failed, error = " << iResult << std::ends;
        throw std::runtime_error(ostr.str());
    }
}

void Network::uninitialize()
{
    int iResult = WSACleanup();
    if (iResult == SOCKET_ERROR)
    {
        std::ostrstream ostr;
        ostr << "Winsock cleanup failed, error = " << WSAGetLastError() << std::ends;
        throw std::runtime_error(ostr.str());
    }
}


std::shared_ptr<TCPServer>& Network::createTCPServer(Mode mode)
{
    m_tcpServers.push_back(std::shared_ptr<TCPServer>(new TCPServer(mode)));
    return m_tcpServers.back();
}


std::shared_ptr<TCPClient>& Network::createTCPClient()
{
    m_tcpClients.push_back(std::shared_ptr<TCPClient>(new TCPClient()));
    return m_tcpClients.back();
}
>>>>>>> upstream/master
