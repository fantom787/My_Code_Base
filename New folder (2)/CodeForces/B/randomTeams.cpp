#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll int n, m;
    cin >> n >> m;
    ll int maxP = n - m + 1;
    ll int max = maxP * (maxP - 1) / 2;
    ll int a = n / m;
    ll int b = n % m;
    ll int min = (m - b) * a * (a - 1) / 2;
    min += (a * (a + 1) * b / 2);

    cout << min << " " << max << endl;
    return 0;
}