#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define max 80
int main()
{
	
	char request[256] = "Hello I am Client are you there";
	char buf[200];
	
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	int i=0;
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	
	
	char st1[30]="exit";
	do
	{ 

                 printf("enter number to do fact ");
                 bzero(buf,max);
	         scanf("%s",&buf);
            
                 write(sock, buf, sizeof(buf)); 
                 bzero(buf,max);
		 read(sock, &buf, sizeof(buf));
		 printf("\n%s\n",&buf);
              
	}
	while(strcmp(request,st1));
	

	
	close(sock);

	return 0;
}

