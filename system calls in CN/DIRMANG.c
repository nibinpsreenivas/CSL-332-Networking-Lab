#include <stdio.h>
#include <dirent.h>

void main()
{
    struct dirent *de;  
    DIR *dr = opendir(".");
 
    if (dr == NULL)
    {
        printf("cannot not open the current directory" );
       
    }
    else
    {
       while ((de = readdir(dr)) != NULL)
       {
            printf("%s\n", de->d_name);
       }
 
       closedir(dr);    
   }
   
}
