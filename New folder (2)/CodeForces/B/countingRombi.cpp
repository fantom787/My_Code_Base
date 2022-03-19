#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int w, h;
    cin >> w >> h;
    ll ans = 0;
    ll ans2 = 0;
    for (int i = 2; i <= w; i += 2)
    {
        ans += (w - i + 1);
    }
    for (int i = 2; i <= h; i += 2)
    {
        ans2 += (h - i + 1);
    }
    cout << ans * ans2 << endl;

    return 0;
}
/*
#include <cstdio>
long long n, m;
int main()
{
    scanf("%d%d", &n, &m);
    printf("%I64d", (m + (m & 1)) * (m / 2) * (n + (n & 1)) * (n / 2) / 4);
}

*/