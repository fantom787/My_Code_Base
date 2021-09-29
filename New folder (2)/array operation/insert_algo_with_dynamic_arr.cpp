#include <iostream>
using namespace std;
void show(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int *arr, int *n, int m,int value)
{
    int temp = arr[m-1];
    arr[m-1] = value;
    realloc(arr,(*n+1)*sizeof(int));
    *n += 1;
    for (int i = *n -1 ; i >m ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[m] = temp;
    
}
int main()
{
    int n = 5;
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    arr[0] = 5;
    arr[1] = 3;
    arr[2] = 2;
    arr[3] = 6;
    arr[4] = 8;
    show(arr, n);
    cout<<"******"<<endl;
    insert(arr,&n,4,5);
    cout<<sizeof(arr)<<endl;
    cout<<"******"<<endl;
    show(arr, n);
    cout<<"******"<<endl;
    insert(arr,&n,1,69);
    show(arr, n);

    return 0;
}