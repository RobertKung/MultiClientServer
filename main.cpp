
#include <iostream>
#include <thread>
#include <string>

#include "ClientSocket.h"
#include "ServerSocket.h"
#include "Socket.h"
#include "SocketException.h"
#include "Client.h"

//no sychronize would cause exception.
//Solution: We should create a server object.
void server(int port_num)
{
    std::cout << "running....\n";
   
  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

    
}


int main()
{
   // using thread to simulate server and client
   
    std::cout<< "start server"<<std::endl;
    
     int res;
   // It would cause race condition if we won't achieve sychronization.
   // Build client object and process it serially.
   
    std::thread t1(server,30000);
    Client c; 

    std::thread t2(&Client::Client_push,&c,2); 
    std::thread t3(&Client::Client_push,&c,3) ; 
    std::thread t4(&Client::Client_pop,&c,std::ref(res)); 
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    
	return 0;
}