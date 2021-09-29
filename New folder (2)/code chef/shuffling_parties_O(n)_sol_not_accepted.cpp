#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    scanf("%d", &n);
    vector<long long int> v1[n];
    long long int m[n];

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++)
        {
            scanf("%d", &temp);
            v1[i].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long int ans = 0, even_arr = 0, odd_arr = 0;
        ans = m[i];
        for (int j = 0; j < m[i]; j++)
        {
            if ((v1[i][j] + j + 1) % 2 == 0)
            {
                if (v1[i][j] % 2 == 0)
                {
                    even_arr += 1;
                }
                else
                {
                    odd_arr += 1;
                }
            }
        }
        long long int diff1 = abs(even_arr - odd_arr);
        printf("%d\n", ans - diff1);
    }

    return 0;
}