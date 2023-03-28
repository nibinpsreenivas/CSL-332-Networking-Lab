#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define max 80
int main()
{

	char server_message[256] = "Hi, Yes you have reached the server!";
	char buf[200];
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
        int val;
	client_socket = accept(server_socket, NULL, NULL);
	// send the message
       int i,fact=1,number;  
	char st1[30]="exit";
	do
	{
                bzero(buf,max);
		if(read(client_socket, &buf, sizeof(buf)))
		{	
			printf(" %s \n", buf);
                        val = atoi(buf);
                         fact=1;
                          for(i=1;i<=val;i++){    
                          fact=fact*i;    
                         }   
                     sprintf(buf,"%d",fact); 
  
		}
		
	        bzero(buf,max);
		write(client_socket, &buf, sizeof(buf));
             
		


		
	}
	while(strcmp(server_message,st1));
	
	
	// close the socket
	close(server_socket);
	
	return 0;
}
