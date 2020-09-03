<<<<<<< HEAD
#include <Network.hpp>
#include <iostream>

=======

#include <Network.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

>>>>>>> upstream/master
int main()
{
	try
	{
<<<<<<< HEAD
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
=======
		std::unique_ptr<Network> network(new Network());
		network->initialize();

		try
		{
			std::shared_ptr<TCPServer> server;
			TCPSocket socket;
			std::uint16_t portNumber = 48000;

			server = network->createTCPServer(Mode::Blocking);
			server->bind(portNumber);
			server->listen();
			std::cout << "Server listening or port " << portNumber << std::endl;
			socket = server->accept();
			std::cout << "Client connected from " << socket.getAddress() << std::endl;

			TCPData buf;
			do {
				buf = socket.receive();
				std::string msg(buf.getData(), buf.getLength());
				if (buf.getLength() > 0)
				{
					std::cout << "Received message from client: " << msg << std::endl;
				}
				std::string data("Here is your data");
				socket.send(&data[0], data.length());
			} while (buf.getLength() > 0);
			std::cout << "Client disconnecting..." << std::endl;
			server->stopListen();
			socket.shutdown();
		}
		catch(std::runtime_error& rt)
		{
			std::cerr << "Server error = " << rt.what() << std::endl;
		}
		catch (std::exception e)
		{
			std::cerr << "C++ exception = " << e.what() << std::endl;
		}

		network->uninitialize();
	}
	catch (std::runtime_error& rt)
	{
		std::cerr << "Server error = " << rt.what() << std::endl;
	}
	catch (std::exception e)
	{
		std::cerr << "C++ exception = " << e.what() << std::endl;
	}
	return 0;
}
>>>>>>> upstream/master
