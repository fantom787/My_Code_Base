#include <iostream>
#include <cmath>
using namespace std;
void print(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
int *binary(int a)
{
    int length = log2(a) + 1;
    int *arr = new int[length];
    int b = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        b = a % 2;
        a = a / 2;
        arr[i] = b;
    }
    return arr;
}

int main()
{
    int a = 255;
    print(binary(a), log2(a) + 1);
    return 0;
}