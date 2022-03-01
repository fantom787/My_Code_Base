#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

void solve()
{
    int n;
    cin >> n;
    vector<int> task(n);
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }
    ll sum1 = 0, sum2 = 0;
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        if (sum1 <= sum2)
        {
            sum1 += task[i];
            i++;
        }
        else
        {
            sum2 += task[j];
            j--;
        }
    }
    cout << max(sum1, sum2) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}