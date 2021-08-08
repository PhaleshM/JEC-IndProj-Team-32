#include<stdio.h>
#include<stdlib.h>
// Header files for defining the type of socket and includes the API
#include<sys/socket.h> 
#include<sys/types.h>
// To store address information
#include<netinet/in.h>
// #include <arpa/inet.h>	//inet_addr
// #include <unistd.h>

int main(){

	// create a socket
	int net_socket;
	net_socket= socket(AF_INET,SOCK_STREAM,0);

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY ;
	int connection_status = connect(net_socket,( struct sockaddr *) &server_address, sizeof(server_address));
	// check for error with connection
	if(connection_status==-1){
		printf("There was an error making a connection to the remote socket \n\n");
	}
	// recieve data from server
	char server_response[256];
	recv(net_socket,&server_response,sizeof(server_response),0);
	// print out the a server's response
	printf("The server set data: %s\n",server_response);

	// close the socket
	pclose(net_socket);
	return 0;
}