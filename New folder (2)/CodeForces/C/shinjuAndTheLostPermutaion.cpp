#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define all(s) s.begin(), s.end()
#define pb push_back
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define sz(x) (int)x.size()

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// Constants
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7;

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

// Mathematical functions
int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int GCD_extended(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> c(n);
    cin >> c;
    ll idx = -1;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 1)
        {
            cnt++;
            idx = i;
        }
    }
    if (cnt != 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        ll del = c[(i + n) % n] - c[((i + n) - 1) % n];
        if (del > 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
/*

#include <bits/stdc++.h>
#define ll long long
#define forr(i, x, y) for(ll i = x; i <= y; i++)
#define forn(i, x, y) for(ll i = x; i >= y; i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 998244353
using namespace std;

ll l, r, ans, ones2[22], ones1[22], zeros1[22], zeros2[22];

void work1(ll x){
    ll pos=0;
    forr(i, 0, 18){
            if(x%2) ones1[i]++;
            else    zeros1[i]++;
            x/=2;
    }
}

void work2(ll x){
    ll pos=0;
    forr(i, 0, 18){
            if(x%2) ones2[i]++;
            else    zeros2[i]++;
            x/=2;
    }
}

void solve(){
    memset(zeros1, 0LL, sizeof(zeros1));
    memset(zeros2, 0LL, sizeof(zeros2));
    memset(ones1, 0LL, sizeof(ones1));
    memset(ones2, 0LL, sizeof(ones2));
    cin>>l>>r;
    forr(i, l, r)   work1(i);
    forr(i, l, r){
            ll x;
            cin>>x;
            work2(x);
    }
    ans=0;
    ll y=1;
    forr(i, 0, 20){
        if(ones1[i]!=ones2[i] || zeros1[i]!=zeros2[i])  ans+=y;
        y*=2;
    }
    cout<<ans<<endl;
}

int main(){
    fast;
//    freopen("input.in", "r", stdin);
    ll t = 1;
    cin>>t;
    while(t--)  solve();
    return 0;
}


*/