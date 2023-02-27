#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

void main()
{
   char buf,a[10],b[10];
   int fd1, fd2;
   printf("enter the name of the source file : ");
   scanf("%s",a);
   
   printf("enter the name of the destination file : ");
   scanf("%s",b);
   
   fd1 = open(a, O_RDONLY);

   if (fd1 == -1)
   {
      printf("Error opening first_file\n");
      close(fd1);
      return;
   }
     
  fd2 = open(b, O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
   if (fd2 == -1)
   {
      printf("Error opening first_file\n");
      close(fd2);
      return;
   }
  
   while(read(fd1, &buf, 1))
   {
     write(fd2, &buf, 1);
   }

   printf("Successful copy\n");

   close(fd1);
   close(fd2);
}
