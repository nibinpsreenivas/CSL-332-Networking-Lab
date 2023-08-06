#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
  int k;
  char buf[100],bufs[100];
  int sock_desc,temp_sock_desc;
  socklen_t len;
  struct sockaddr_in client,server;
  
  sock_desc=socket(AF_INET,SOCK_STREAM,0);
  
  if(sock_desc==-1)
    printf("error");
    
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=2004;
  
  client.sin_family=AF_INET;
  client.sin_addr.s_addr=INADDR_ANY;
  client.sin_port=2004;
    
  k=bind(sock_desc,(struct sockaddr*)&server,sizeof(server));
  if(k==-1)
      printf("error");
  
   
   k=listen(sock_desc,5);
   
    if(k==-1)
     printf("error");
   
    len = sizeof(client);  
    temp_sock_desc = accept(sock_desc,(struct sockaddr*)&client,&len);
    
    if(temp_sock_desc==-1)
     printf("error");
    
   while(1)
   {
     
       k= recv(temp_sock_desc,buf,100,0);
        if(k==-1)
           printf("error");
       int n=atoi(buf);
       if(n==1111)
       {
         printf("\n exiting........");
         exit(0);
       }
      printf("\nThe message recived from client is %s",buf);
         printf("\nenter message to send to client");
         fgets(bufs,100,stdin);
      
       k= send(temp_sock_desc,bufs,100,0);
       if(k==-1)
         printf("error");
       
     }
     
     return 0;
     
  }
       
      
      
      
      
      
      
      
   
    
