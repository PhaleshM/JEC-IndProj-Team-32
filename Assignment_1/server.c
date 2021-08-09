#include<stdio.h>
#include<stdlib.h>
// Header files for defining the type of socket and includes the API
#include<sys/socket.h> 
#include<sys/types.h>
// To store address information
#include<netinet/in.h>
#include<string.h>
// #include <arpa/inet.h>	//inet_addr
// #include <unistd.h>

int main(){

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
    if(client_socket>=0){
        printf("Connected\n");
    }
    
    char server_response[256];
    int i=1;
    do{
    char *response="hi ";
    recv(client_socket,server_response,256,0);
    printf("Hello from %s\n",server_response);
    // send message
    send(client_socket,server_response,sizeof(server_response),0);
    printf("Sent hello for %s\n",server_response);
        i++;
    }while(i<=4);
    // close socket
    // close(server_socket);

    return 0;
}