#include <stdio.h>

void strcat1(char *str1, char *str2)
{
     int j = sizeof(str1) + 1;
     for (int i = 0; i < (sizeof(str2)+1) ; i++)
     {
          str1[j] = str2[i];
          j++;
     }
     str1[j] = '\0';
}

int main()
{
     char str[] = "ambuj";
     int size1 = sizeof(str);
     char str2[] = "kumar";
     printf("inptut string 1 =  %s\n", str);
     printf("inptut string 2 =  %s\n", str2);
     strcat1(str, str2);
     printf("output string  =  %s\n", str);

     return 0;
}