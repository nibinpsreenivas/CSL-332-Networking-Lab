#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>



int main() { 
   int k, num;
   int sock_desc;
   socklen_t len;
   time_t current_time;
	
   struct sockaddr_in server, client;
   sock_desc = socket(AF_INET, SOCK_DGRAM,0);
   if (sock_desc == -1) 
   {
        printf("Could not open a socket");
	return 1;
   }
   server.sin_family=AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port=htons(4001);
        
   k=bind(sock_desc,(struct sockaddr *)&server,sizeof(server));
   if(k!=0) 
   {
      printf("Could not bind socket");
      return 1;
   }
   len = sizeof(client);
   while(1) 
   {
      recvfrom(sock_desc, &num,sizeof(num), 0, (struct sockaddr *)&client,&len);
      current_time = time(NULL);
      printf("\ntime at which Client requested is: %s",ctime(&current_time));
sendto(sock_desc, &current_time,sizeof(current_time),0, (struct sockaddr *)&client, sizeof(client));
   }

	return 0;
}
