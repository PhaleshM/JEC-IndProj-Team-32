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
	
	char *hello1 ="client1";
	char *hello2 ="client2";
	char *hello3 ="client3";
	char *hello4 ="client4";

	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY ;
	int connection_status = connect(net_socket,( struct sockaddr *) &server_address, sizeof(server_address));
	// check for error with connection
	if(connection_status==-1){
		printf("There was an error making a connection to the remote socket \n\n");
	}else{
		printf("Connected\n");
	}
	char client_response[256];
	int i=1;
	do{
	// send data from server
	
	send(net_socket,hello1,256,0);
	printf("Sent hello %s\n",hello1);
	// recieve data from server
	recv(net_socket,&client_response,sizeof(client_response),0);
	// print out the a server's response
	printf("Welcome from server, %s\n",client_response);
	i++;
	}while(i<=4);

	// close the socket
	// close(net_socket);
	return 0;
}