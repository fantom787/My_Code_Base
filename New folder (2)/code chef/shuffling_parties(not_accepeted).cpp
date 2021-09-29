#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int element;
    cin >> n;
    vector<int> v1[n];
    int m[n];

    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++)
        {
            cin >> element;
            v1[i].push_back(element);
        }
    }

    int ans, max_ans;
    for (int i = 0; i < n; i++)
    {
        ans = 0;
        max_ans = 0;
        for (int k = 0; k < m[i]; k++)
        {
            for (int j = 0; j < m[i]; j++)
            {
                ans += (v1[i][j] + j + 1) % 2;
            }
            swap(v1[i][k], v1[i][(k + 1) % m[i]]);
            max_ans = max(ans, max_ans);
            ans = 0;
        }
        cout << max_ans << endl;
    }

    return 0;
}