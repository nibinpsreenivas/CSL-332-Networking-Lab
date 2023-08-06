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
    while (1)
   {
      printf("Enter the data to be sent to the server: ");
      fgets(buf, 100, stdin);
      if (atoi(buf) == 1111)
      {
         sendto(sock_desc, buf, 100, 0, (struct sockaddr*)&server, sizeof(server));
         printf("\nExiting.....");
         break;
       }
      sendto(sock_desc, buf, 100, 0, (struct sockaddr*)&server, sizeof(server));
      if (k < 0)
      {
       printf("Error in sendto!!!\n");
      return 1;
     }
     len = sizeof(server);
     k = recvfrom(sock_desc, buf, 100, 0, (struct sockaddr*)&server, &len);
     if (k < 0)
     {
        printf("Error in recvfrom()!");
        return 1;
     }
     printf("Server response: %s", buf);
   }
  return 0;
 }
