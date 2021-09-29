#include <stdio.h>
#include <stdlib.h>
void insert(int *arr, int *n, int v)
{
     (int *)realloc(arr, sizeof(int) *((*n)+1));
     arr[*n ] = v;
     *n = *n+1;

}
int display(int *arr, int n)
{
     for (int i = 0; i < n; i++)
     {
          printf("%d ", arr[i]);
     }
     printf("\n");
}
int main()
{
     int n = 3;
     int*ptr=&n;
     int arr[n];
     arr[0] = 1;
     arr[1] = 2;
     arr[2] = 3;
     display(arr, n);
     insert(arr,ptr,5);
     display(arr,*ptr);

     return 0;
}