#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) x.begin(), x.end()

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totalSum += a[i];
    }
    sort(a);
    reverse(all(a));
    ll red = a[0];
    ll blue = a[n - 1] + a[n - 2];
    ll i = 1;
    ll j = n - 3;
    while (red <= blue && i < j)
    {
        red += a[i++];
        blue += a[j--];
    }
    if (red > blue)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
/*
Logic for B

Sort then take first two for blue and last one for red, and assign i=2, j=n-1.
Now run a loop while red is less than blue and i < j , inside this blue += a[i], red += a[j], i++, j--.

Now outside the loop print yes if red > blue else no.

That's all.
*/