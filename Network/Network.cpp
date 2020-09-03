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


