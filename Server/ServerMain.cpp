#include <Network.hpp>
#include <iostream>

int main()
{
	try
	{
		std::unique_ptr<Network> network( new Network() );

		network->Startup();
		//std::shared_ptr<TCPServer> or TCPServer* server = network->CreateTCPServer();
		//server->Bind();?
		//server->Accept();?
	}
	catch ( std::runtime_error& runtimeErr )
	{
		std::cerr << runtimeErr.what() << std::endl;

		
	}
}
