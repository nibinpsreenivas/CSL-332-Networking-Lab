#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
   int k;
   char buf[100];
   int sock_desc,temp_sock_desc;
   socklen_t len;
   struct sockaddr_in server,client;
   
   sock_desc = socket(AF_INET,SOCK_STREAM,0);
   
   if(sock_desc==-1)
   {
     printf("\nerror in sock_desc");
   }
   
   server.sin_family= AF_INET;
   server.sin_addr.s_addr=INADDR_ANY;
   server.sin_port = 3001;
   
   client.sin_family= AF_INET;
   client.sin_addr.s_addr=INADDR_ANY;
   client.sin_port = 3001;
   
   k=bind(sock_desc,(struct sockaddr*) &server,sizeof(server));
   
   
   if(k==-1)
   {
     printf("\nerror in bind");
   }
   
   k=listen(sock_desc,5);
   
   if(k==-1)
   {
     printf("\nerror in listen");
   }
   len=sizeof(client);
   
   temp_sock_desc = accept(sock_desc,(struct sockaddr*) &client,&len);
   
    if(temp_sock_desc==-1)
    {
     printf("\nerror in temp_sock_desc");
    }
    while(1)
    {
         k=recv(temp_sock_desc,buf,100,0);
         if(k==-1)
         {
           printf("\nerror in recv");
         }
        
         int c= atoi(buf);
      
         if(c==1111)
         {
           printf("\n Exiting.....");
           exit(0);
         }
         int flag=0;
         for(int i=2;i<c;i++)
         {
           if(c%i==0)
             flag=1;
         }
            printf("\nThe number from client is %s",buf);
         sprintf(buf,"%d",flag);
         k=send(temp_sock_desc,buf,100,0);
         if(k==-1)
         {
           printf("\nerror in sending");
         }
       }   
        
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
