#include "Client.h"

Client::Client()
{

   this->Client_connection();
   /*try{
        client_socket = std::make_shared<ClientSocket>("localhost",30000);
    
    std::string reply;
      try{
      	  std::cout<<"shared pointer count: "<<client_socket.use_count()<<std::endl;
          (*client_socket.get())<<"Test message.";
          (*client_socket.get())>>reply;
        }catch(SocketException& e){} 

      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";   


   }catch(SocketException& e)
   {
   	std::cout << "Exception was caught:" << e.description() << "\n";
   }*/
    

}

Client::~Client()
{
  // delete tq;
}

void Client::Client_connection()
{
	std::lock_guard<std::mutex> lk(_mutex);	//mutex , implement mutal exclusion.
	try{
        client_socket = std::make_shared<ClientSocket>("localhost",30000);
    
    std::string reply;
      try{
      	  std::cout<<"shared pointer count: "<<client_socket.use_count()<<std::endl;
          (*client_socket.get())<<"Test message.";
          (*client_socket.get())>>reply;
        }catch(SocketException& e){} 

      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";   


   }catch(SocketException& e)
   {
   	std::cout << "Exception was caught:" << e.description() << "\n";
   }
}

void Client::Client_push(int value)
{
   //std::lock_guard<std::mutex> lk(_mutex);
   tq.push(value);
}   

void Client::Client_pop(int& value)
{
	tq.pop(value);
	std::cout<<"value: "<<value<<std::endl;
}   

bool Client::Client_empty()
{
	return tq.empty();
}   