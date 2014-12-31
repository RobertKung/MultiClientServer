# Makefile for the socket programming example
#

simple_server_test = main.o ServerSocket.o ClientSocket.o Socket.o Client.o 
CXXFLAGS=-g -std=c++11 -Wall -pedantic -pthread
#all : simple_server simple_client
all : simple_test

simple_test: $(simple_server_test)  
	g++ $(CXXFLAGS) -o simple_test $(simple_server_test)
#simple_server: $(simple_server_objects)
#	g++ -o simple_server $(simple_server_objects)


#simple_client: $(simple_client_objects)
#	g++ -o simple_client $(simple_client_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
ClientSocket: ClientSocket.cpp
Client: Client.cpp

#simple_server_main: server.cpp
#simple_client_main: client.cpp
simple_test: main.cpp

clean:
	#rm -f *.o simple_server simple_client
	rm -f *.o simple_test