// <------------------------------------- Headers Files ------------------------------------->
#include <bits/stdc++.h>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define vpi vector<pii>
#define ff first
#define ss second
#define pb push_back
#define bitcnt1 __builtin_popcount
#define mp make_pair
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define lb lower_bound
#define up upper_bound
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key
#define all(a) a.begin(), a.end()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

using namespace std;
// <------------------------------------- Code ------------------------------------->

// const int N = 1e5 + 10;
// const int mod = 1e9 + 7;

void solve(int tt)
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    ll ans = 0;
    unordered_map<int, int> mm;
    rep(i, 0, n)
    {
        int l = 0;
        rrep(j, 32, 0)
        {
            if (a[i] & (1 << j))
            {
                l = j;
                break;
            }
        }
        mm[l]++;
    }
    for (auto &it : mm)
    {
        ll m = it.ss;
        if (m <= 1)
            continue;
        ans += (m * (m - 1)) / 2;
    }

    cout << ans << endl;
}

int main()
{
    clock_t begin_69 = clock();
    fast_io;

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve(t);
    }

#ifndef ONLINE_JUDGE
    clock_t terminator_69 = clock();
    cerr << "\nExecuted In: " << double