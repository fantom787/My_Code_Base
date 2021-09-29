#include <iostream>
using namespace std;

void show(int *arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}
void reverse(int *arr , int n)
{
    for (int i = 0; i < (n/2); i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
    
}

int main()
{
    int n = 11;
    int arr[n] = {4,2,8,4,1,54,87,25,54,79,21};
    show(arr,n);
    cout<<"************"<<endl;
    sort(arr,n);
    show(arr,n);
    cout<<"************"<<endl;
    reverse(arr,n);
    show(arr,n);




    return 0;
}