#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() 
{
    int k;
    int sock_desc;
    int num = 1;
    double rtt1;
    clock_t start_t, end_t;
    
    
    time_t start_time, rtt, current_time;
    struct sockaddr_in server, client;
    socklen_t len;
	
    sock_desc = socket(AF_INET, SOCK_DGRAM,0);
    if (sock_desc == -1) 
	{
		printf("Could not open a socket");
		return 1;
	}
	
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(4001);
    
   
    
    if(k!=0) 
    {
       printf("Could not bind socket");
		return 1;
    }
    
    start_time = time(NULL);
    start_t = clock();
    sendto(sock_desc,&num, sizeof(num), 0, (struct sockaddr *)&server, sizeof(server));
    len = sizeof(client);
    recvfrom(sock_desc, &current_time, sizeof(current_time), 0, (struct sockaddr *)&client, &len);
    end_t = clock();
    rtt1 = end_t - start_t;
    rtt1=rtt1/2;
    rtt = time(NULL) - start_time;
    current_time += rtt / 2;
    printf("Server's Time: %s is delyed by %f milli sec\n", ctime(&current_time),rtt1);

	return 0;
}

