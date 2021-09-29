#include <stdio.h>
int greater(int a, int b)
{
     return a > b ? a : b;
}
int strcmp1(char *str1, char *str2)
{
     int size1 = sizeof(str1);
     int size2 = sizeof(str2);
     int size = greater(size1, size2);
     for (int i = 0; i < size; i++)
     {
          if (str1[i] != str2[i])
          {
               return (int)(str1[i] - str2[i]);
          }
     }
     return 0;
}
void reverse(char *str)
{
     int j = sizeof(str) + 1;
     for (int i = 0; i < j / 2; i++)
     {
          char temp = str[i];
          str[i] = str[j - i - 1];
          str[j - i - 1] = temp;
     }
}

int main()
{
     char str1[] = "anjna";
     char str2[] = "anjna";
     printf("input string : %s\n", str2);
     reverse(str1);
     printf("reversed string : %s\n", str1);
     if (strcmp1(str1, str2) != 0)
     {
          printf("the strings are not palnedromic \n");
     }
     else
     {
          printf("the strings are  palnedromic \n");
     }

     return 0;
}