#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    //create a socket
    int net_socket;
    net_socket = socket(AF_INET,SOCK_STREAM,0);

    //specify an address for the socket;
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

   int con_status = connect(net_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    //check for error with the connection
    if(con_status == -1)
    printf("Error\n");
    
    //recieve data from server
    char buffer[256];
    recv(net_socket, &buffer, sizeof(buffer), 0);
    
    //print out the server's response
    printf("The Server sent the data : %s\n",buffer);

    //close the socket
    close(net_socket);
    return 0;
}
