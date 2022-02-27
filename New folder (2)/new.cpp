#include <iostream>
using namespace std;

bool incdec(int *arr, int n, int flag, int prev)
{
    if (n == 1)
    {
        if ((!flag && prev > arr[0]) || (flag && prev < arr[0]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if ((!flag && prev > arr[0]) || (flag && prev < arr[0]))
    {
        return incdec(arr + 1, n - 1, flag, arr[0]);
    }
    else if (!flag && prev < arr[0])
    {
        flag = 1;
        return incdec(arr + 1, n - 1, flag, arr[0]);
    }
    else
    {
        return false;
    }
    return true;
}
int main()
{
    int arr[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (incdec(arr + 1, n, 0, arr[0]))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}