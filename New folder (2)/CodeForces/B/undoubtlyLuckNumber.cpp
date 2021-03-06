#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ppc __builtin_popcount
#define ppcll _builtin_popcount

void f(int n, ll curr, int a, int b, set<ll> &st)
{
    if (curr > n)
    {
        return;
    }
    st.insert(curr);
    f(n, (curr * 10) + a, a, b, st);
    f(n, (curr * 10) + b, a, b, st);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    set<ll> st;
    rep(i, 1, 10)
    {
        f(n, i, i, 0, st);
        rep(j, i + 1, 10)
        {
            f(n, 0, i, j, st);
        }
    }
    cout << st.size() - 1 << endl;
    return 0;
}