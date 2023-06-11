#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define OUTPUT_RATE 1       
int main() 
{
    int BUCKET_CAPACITY;
    printf("Enter the bucket capacity:");
    scanf("%d",&BUCKET_CAPACITY);
    int bucket_size = 0;  

    while (true) 
    {
       
        int incoming_packets = rand() % 5;

        printf("Incoming packets: %d\n", incoming_packets);
        bucket_size += incoming_packets;
        if (bucket_size > BUCKET_CAPACITY) {
            printf("Bucket overflow! Dropping packets: %d\n", bucket_size - BUCKET_CAPACITY);
            bucket_size = BUCKET_CAPACITY;  
        }
        if (bucket_size > 0) 
        {
            int outgoing_packets = bucket_size < OUTPUT_RATE ? bucket_size : OUTPUT_RATE;

            printf("Outgoing packets: %d\n", outgoing_packets);
            bucket_size -= outgoing_packets;
        }

        sleep(1);  
    }

    return 0;
}
