#include <bits/stdc++.h>
using namespace std;

int main()
{

        int n, loop_counter = 0, sum = 0;
        cin >> n;
        int arr[n][3];
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < 3; j++)
                {
                        cin >> arr[i][j];
                }
        }
        for (int i = 0; i < n; i++)
        {
                sum = 0;
                for (int j = 0; j < 3; j++)
                {
                        sum += arr[i][j];
                }
                if (sum >= 2)
                {
                        loop_counter += 1;
                }
        }
        cout << loop_counter;
        return 0;
}