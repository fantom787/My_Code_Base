#include <bits/stdc++.h>
using namespace std;

// Constants
#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// debug
#define debug(x)       \
    cout << #x << " "; \
    _print(x);         \
    cout << endl;
void _print(ll t)
{
    cout << t;
}
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }

// macros
#define endl "\n";
#define all(s) s.begin(), s.end()
#define pb push_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x) // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x) // gives the most significant bit of the number
#define F first
#define S second
#define int long long
#define getunique(x)         \
    {                        \
        set<int> st(all(x)); \
        x.assign(all(st));   \
    }

// custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}

/*
write down ur inner voice dont suppress it
*/

vector<int> edges[150005];
vector<int> label(150005);
vector<int> sz(150005);
vector<int> nedges(150005);

// Approach ->

void relable(int v, int target)
{
    if (label[v] == target)
    {
        return;
    }
    label[v] = target;
    for (auto it : edges[v])
    {
        relable(it, target);
    }
}

void merge(int u, int v)
{
    edges[u].pb(v);
    edges[v].pb(u);

    int cu = label[u];
    int cv = label[v];
    nedges[cu]++;
    if (cu == cv)
    {
        return;
    }
    if (sz[cu] > sz[cv])
    {
        swap(cu, cv);
        swap(u, v);
    }
    relable(u, cv);
    sz[cv] += sz[cu];
    nedges[cv] += nedges[cu];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        label[i] = i;
        sz[i] = 1;
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        merge(u, v);
    }
    bool possible = 1;
    for (int i = 0; i < n; i++)
    {
        int totaledge = nedges[label[i]];
        int sizeofcomp = sz[label[i]];
        if (totaledge != (sizeofcomp * (sizeofcomp - 1) / 2))
        {
            possible = 0;
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // seive();
    // seev();
    int n = 1;
    while (n--)
    {
        solve();
    }
    return 0;
}
/* stuff you should look for
 * i>j wale sare chahiye to prefix wala lga do sir jisme curr ko calc kro prev se and fir usko map kr do
 * a+b = a^b + 2*a&b
 * uncertain ko pehle nipta lo sir
 * special cases (n=1?)/ odd/even index
 * sir square wala bhi soch lo
 * consecutive elements ka scene hai to genedy apraoch lga do sir
 * follow the basics koi nya try kr rha hai toh uske primitive try kr
 * cool hoja bsdk answer ez hai
 * copy pe bna ke dekh lo sir
 * floor and ciel ka panga dekh lo sir
 * pani pee aa
 * Question Dobara padh bsdk
 * int overflow, array bounds
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * TRY USING LONG LONG INT
 * XOR --> ALWAYS TRY 45132
 */