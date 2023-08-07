#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 3001

int main() 
{
    int k;
    int sock_desc, temp_sock_desc, read_size;
    socklen_t len;
    struct sockaddr_in server, client;
    char buf[100];

    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) 
    {
        printf("Socket creation failed");
     
    }

    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);
  
    k=bind(sock_desc, (struct sockaddr*)&server, sizeof(server));
    if (k < 0) 
    {
        printf("Binding failed");
    }

    listen(sock_desc, 5);

    printf("FTP server listening on port %d...\n", PORT);
    len = sizeof(client);
      
      temp_sock_desc = accept(sock_desc, (struct sockaddr*)&client,&len);
        if (temp_sock_desc < 0) 
        {
            printf("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        FILE* file = fopen("server.txt", "w");
        if (!file) 
        {
            printf("File opening failed");
            exit(EXIT_FAILURE);
        }

        while ((read_size = recv(temp_sock_desc, buf, sizeof(buf), 0)) > 0) 
        {
            fwrite(buf, sizeof(char), read_size, file);
            printf("\n%s",buf);
        }

        fclose(file);
        printf("File received and saved as 'server.txt'\n");
        

    return 0;
}


