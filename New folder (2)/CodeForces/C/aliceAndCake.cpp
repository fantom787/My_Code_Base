#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7
#define ppc __builtin_popcount
#define ppcll _builtin_popcount
#define sz(x) (int)x.size()

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    map<ll, ll> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }
    multiset<ll> st;
    st.insert(accumulate(all(arr), 0LL));
    while (st.size())
    {
        ll front = *(st.begin());
        st.erase(st.begin());
        ll sum = mp.begin()->first;
        if (sum > front)
        {
            break;
        }
        if (mp.count(front))
        {
            mp[front]--;
            if (mp[front] == 0)
            {
                mp.erase(front);
            }
        }
        else
        {
            ll x = front / 2;
            ll y = front - x;
            st.insert(x);
            st.insert(y);
        }
    }
    if (mp.size())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}