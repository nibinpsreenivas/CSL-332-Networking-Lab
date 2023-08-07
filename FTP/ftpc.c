#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 3001


int main() 
{
    int k;
    socklen_t len;
    int sock_desc;
    struct sockaddr_in server;
    char buf[100];

 
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock_desc == -1) 
    {
        printf("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    k=connect(sock_desc, (struct sockaddr*)&server, sizeof(server));
    if (k < 0) 
    {
        printf("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to FTP server at %d\n",PORT);

    
    FILE* file = fopen("client.txt", "r");
    if (!file) 
    {
        printf("File opening failed");
        exit(EXIT_FAILURE);
    }

    while (!feof(file)) 
    {
        size_t read_size = fread(buf, sizeof(char), sizeof(buf), file);
        k=send(sock_desc, buf, read_size, 0) ;
        if (k< 0) 
        {
            printf("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    printf("File sent successfully\n");

    
    return 0;
}


