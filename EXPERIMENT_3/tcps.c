#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
char username[MAX];
char password[MAX];
char text[MAX];

void func(int connfd)
{
   char temp;
   int i = 0;
   int j = strlen(text) - 1;
   read(connfd, username, sizeof(username));
   read(connfd, password, sizeof(password));
   printf("CLIENT - Username: %s\n", username);
   printf("CLIENT - Password: %s\n", password);
   printf("Authenticate? - Enter 'y' or 'n': ");
   scanf("%s", text);

   write(connfd, text, sizeof(text));
   
   if (strcmp(text, "n") == 0)
      exit(0);

   read(connfd, text, sizeof(text));
   
      while (i < j)
      {
       temp = text[i];

       text[i] = text[j];
       text[j] = temp;
       i++;
       j--;
      }

   write(connfd, text, sizeof(text));
   printf("The reverse text is : %s \n", &text);
   exit(0);
}

void main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed.\n");
        exit(0);
    }
    else
    {
       printf("Socket successfully created.\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

     if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
     {
         printf("Socket bind failed.\n");
         exit(0);
     }
     else
     {
        printf("Socket successfully binded.\n");
     }

    if ((listen(sockfd, 5)) != 0)
    {
      printf("Listen failed.\n");
      exit(0);
    }
    else
    {
      printf("Server listening.\n");
    }
    len = sizeof(cli);
    connfd = accept(sockfd, (SA *)&cli, &len); 
    
    if (connfd < 0)
    {
       printf("Server accept failed.\n");
       exit(0);
    }
    else
    {
       printf("Client accepted by server.\n");
    }

func(connfd);
close(sockfd);
}
