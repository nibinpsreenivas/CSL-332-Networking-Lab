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
   
   client.sin_family= AF_INET;
   client.sin_addr.s_addr=INADDR_ANY;
   client.sin_port = 3001;
   
 
   len=sizeof(client);
   
    k= connect(sock_desc,(struct sockaddr*) &client,sizeof(client));
   
    if(temp_sock_desc==-1)
    {
     printf("\nerror in temp_sock_desc");
    }
    while(1)
    {
       
         printf("\nenter the number");
         fgets(buf,100,stdin);
         
         int c= atoi(buf);
         if(c==1111)
         {
           k=send(sock_desc,buf,100,0);
            if(k==-1)
            {
              printf("\nerror in sending");
            }
           printf("\n Exiting.....");
           exit(0);
         }
         k=send(sock_desc,buf,100,0);
         if(k==-1)
         {
           printf("\nerror in sending");
         }
         
         k=recv(sock_desc,buf,100,0);
         if(k==-1)
         {
           printf("\nerror in recv");
         }
        
         if(atoi(buf)==0)
         {
           printf("\nThe number is prime number");
         }
         else
         {
           printf("\nThe number is not prime number");
         }
       }   
        
   }
   
   
   
   
   
