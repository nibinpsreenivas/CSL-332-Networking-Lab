#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
   int k;
   char buf[100];
   int sock_desc;
   socklen_t len;
   struct sockaddr_in client;
   
   sock_desc=socket(AF_INET,SOCK_STREAM,0);
   if(sock_desc==-1)
      printf("error");
   client.sin_family=AF_INET;
   client.sin_addr.s_addr=INADDR_ANY;
   client.sin_port = 2004;
   
   k=connect(sock_desc,(struct sockaddr*) &client,sizeof(client));
   if(k==-1)
      printf("error");
   while(1)
   {
      printf("\n Enter value to be send to server");
      fgets(buf,100,stdin);
     if(atoi(buf)==1111)
     {
       send(sock_desc,buf,100,0);
       printf("exiting.....");
       exit(0);
     }
     k=send(sock_desc,buf,100,0);
     if(k==-1)
      printf("error");
     k=recv(sock_desc,buf,100,0);
     if(k==-1)
      printf("error");
     printf("\nThe message from server is %s",buf);
   }
   close(sock_desc);
   return 0;
  }
     
