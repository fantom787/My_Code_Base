#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, k, loop_counter = 0;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
                cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
                if (arr[i] >= arr[k - 1] && arr[i] > 0)
                {
                        loop_counter += 1;
                }
        }
        cout << loop_counter;

        return 0;
}