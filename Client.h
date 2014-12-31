#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include "ClientSocket.h"
#include "SocketException.h"
#include "TQueue.h"


class Client{

     public:
     	Client();
     	~Client();
        Client(const Client& client) = delete;
        Client& operator=(const Client& other)=delete;
        void Client_connection();
     	void Client_push(int value);
     	void Client_pop(int& value); 
     	bool Client_empty();
     private:
        std::mutex _mutex;
        std::shared_ptr<ClientSocket> client_socket;
        TQueue<int> tq;
};

#endif