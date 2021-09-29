#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    int bl, sl, sum;
    for (int i = 0; i < n; i++)
    {
        sum = arr[i][0] + arr[i][1] + arr[i][2];
        bl = arr[i][3];
        sl = arr[i][4];
        if (sum - arr[i][0] <= bl && arr[i][0] <= sl)
        {
            cout << "YES" << endl;
        }
        else if (sum - arr[i][1] <= bl && arr[i][1] <= sl)
        {
            cout << "YES" << endl;
        }
        else if (sum - arr[i][2] <= bl && arr[i][2] <= sl)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
