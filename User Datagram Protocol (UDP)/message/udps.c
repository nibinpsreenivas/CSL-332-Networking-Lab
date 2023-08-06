#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netdb.h>
int main()
{
    char buf[100];
    int k;
    int sock_desc;
    socklen_t len;
    struct sockaddr_in server, client;
    sock_desc = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_desc == -1)
    {
       printf("Error in socket()");
       return 1;
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(3001);
    k = bind(sock_desc, (struct sockaddr*)&server, sizeof(server));
    if (k < 0)
    {
       printf("Error in bind()!!!");
       return 1;
     }
    len = sizeof(client); .
    printf("\nServer waiting...\n");
    while (1)
   {
      k = recvfrom(sock_desc, buf, 100, 0, (struct sockaddr*)&client, &len);
      if (k < 0)
      {
        printf("Error in recvfrom()!");
        return 1;
      }
      if (atoi(buf) == 1111)
      {
         printf("\nExiting......");
         break;
       }
      printf("\nServer got a message from client: %s", buf);
      printf("\nEnter message to be sent to the client: ");
      fgets(buf, 100, stdin);
      k = sendto(sock_desc, buf, 100, 0, (struct sockaddr*)&client, sizeof(client));
      if (k < 0)
      {
         printf("Error in sendto()!");
         return 1;
      }
   }
   
   return 0;
}
