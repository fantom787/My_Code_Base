#include <stdio.h>
int indata(int m, int n,int arr[m][n])
{
     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               scanf("%d", &arr[i][j]);
          }

     }
}
int outdata(int m, int n,int arr[m][n])
{
     for (int i = 0; i < m; i++)
     {
          for (int j = 0; j < n; j++)
          {
               printf("%d", arr[i][j]);
          }

          printf("\n");
     }
}
int main()
{
     int n = 3, m = 3;
     int arr[m][n];
     indata(m,n,arr);
     outdata(m,n,arr);

     return 0;
}