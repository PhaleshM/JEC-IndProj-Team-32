#include<stdio.h>
#include<stdlib.h>
// Header files for defining the type of socket and includes the API
#include<sys/socket.h> 
#include<sys/types.h>
// To store address information
#include<netinet/in.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>

int main(){
    char server_message[256]="You have reached the server";

    int server_socket;
    server_socket=socket(AF_INET,SOCK_STREAM,0);

    // define the server sddress
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9002);
    server_address.sin_addr.s_addr=INADDR_ANY;

    //  bind the socket to our speciified IP and port
    bind(server_socket,(struct sockaddr*) &server_address,sizeof(server_address));

    listen(server_socket,5);

    int client_socket;
    client_socket=accept(server_socket,NULL,NULL);
    
    // send message
    send(client_socket,server_message,sizeof(server_message),0);

    // close socket
    pclose(server_socket);

    return 0;
}