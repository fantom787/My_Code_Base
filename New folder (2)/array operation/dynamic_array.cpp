#include <iostream>
using namespace std;

int **indata(int a, int b)
{
    int **ptr = (int **)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        ptr[i] = (int *)malloc(b * sizeof(int));
    }
    cout << "input your data" << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << "entre your element no : " << j + 1 << "of  coloumn  :" << i + 1;
            cin >> ptr[i][j];
        }
    }
    return ptr;
}
int get_data(int **arr,int a,int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << " element no : " << j + 1 << "of  coloumn  :" << i + 1<<"is :"<<arr[i][j]<<endl;
        }
        
    }
    return 0;
}

int main()
{
    int a = 3;
    int b = 4;
    int **arr = indata(a, b);
    get_data(arr,a,b);

    return 0;
}