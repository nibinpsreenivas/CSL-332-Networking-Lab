#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

#define BUFFER_SIZE 1024
int is_prime(int n); 

int main(int argc, char *argv[]) {

    int server_socket, client_socket, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_size = sizeof(client_addr);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if ((server_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {

        perror("socket creation failed");

        exit(EXIT_FAILURE);

    }

    if (bind(server_socket, (const struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    while (true) {
        n = recvfrom(server_socket, buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *) &client_addr, &addr_size);

        buffer[n] = '\0';
        int num = atoi(buffer);
        printf("\nvalue recevied from client is %d",num);
        int isPrime = is_prime(num);
        char *val;
        if(isPrime==1)
          val="Prime";
        else
          val="Not Prime";
     
        sendto(server_socket, val, strlen(val), MSG_CONFIRM, (const struct sockaddr *) &client_addr, addr_size);

    }

    close(server_socket);

    return 0;

}

int is_prime(int n) 
{

    if (n <= 1) 
      return 0;

    if (n <= 3) 
      return 1;

    if (n % 2 == 0 || n % 3 == 0)
     return 0;

    for (int i = 5; i * i <= n; i = i + 6)

        if (n % i == 0 || n % (i + 2) == 0)

            return 0;

    return 1;

}
