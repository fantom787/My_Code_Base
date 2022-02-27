#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int n, m;
    cin >> n >> m;
    long long int ans = 0;
    long long int prev = 1;
    while (m--)
    {
        int temp;
        cin >> temp;
        ans += (temp - prev + n) % n;
        prev = temp;
    }
    cout << ans << endl;
    return 0;
}