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

bool f(int sum, int sub, int multi, int div)
{
    int a = (sum + sub) / 2;
    int b = (sum - sub) / 2;
    if (a < 1 || a > 10000 || b < 1 || b > 10000)
    {
        return false;
    }
    int cnt = 0;
    if (a + b == sum)
        cnt++;
    if (a - b == sub)
        cnt++;
    if (a * b == multi)
        cnt++;
    if (a / b == div)
        cnt++;
    return cnt == 4;
}

void solve()
{
    vector<ll> a(4);
    cin >> a;
    vector<ll> t = {0, 1, 2, 3};
    do
    {
        if (f(a[t[0]], a[t[1]], a[t[2]], a[t[3]]))
        {
            cout << (a[t[0]] + a[t[1]]) / 2 << " " << (a[t[0]] - a[t[1]]) / 2 << endl;
            return;
        }

    } while (next_permutation(all(t)));
    cout << -1 << " " << -1 << endl;
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

ll arr[4];
        for (int i = 0; i < 4; i++)
            cin >> arr[i];
        sort(arr, arr + 4);
        ll a1 = (arr[2] + arr[0]) / 2;
        ll b1 = arr[2] - a1;
        ll a2 = (arr[2] + arr[1]) / 2;
        ll b2 = arr[2] - a2;
        ll a3 = (arr[3] + arr[0]) / 2;
        ll b3 = arr[3] - a3;
        ll a4 = (arr[3] + arr[1]) / 2;
        ll b4 = arr[3] - a4;
        if ((a1 % 1 == 0) && (a1 != 0) && (b1 % 1 == 0) && (b1 != 0))
            if ((a1 / b1 == arr[1]) && (a1 * b1 == arr[3]) && (a1 >= 1) && (b1 >= 1) && (a1 <= 10000) && (b1 <= 10000))
            {
                cout << a1 << " " << b1 << endl;
                continue;
            }
        if ((a2 % 1 == 0) && (a2 != 0) && (b2 % 1 == 0) && (b2 != 0))
            if ((a2 / b2 == arr[0]) && (a2 * b2 == arr[3]) && (a2 >= 1) && (b2 >= 1) && (a2 <= 10000) && (b2 <= 10000))
            {
                cout << a2 << " " << b2 << endl;
                continue;
            }
        if ((a3 % 1 == 0) && (a3 != 0) && (b3 % 1 == 0) && (b3 != 0))
            if ((a3 / b3 == arr[1]) && (a3 * b3 == arr[2]) && (a3 >= 1) && (b3 >= 1) && (a3 <= 10000) && (b3 <= 10000))
            {
                cout << a3 << " " << b3 << endl;
                continue;
            }
        if ((a4 % 1 == 0) && (a4 != 0) && (b4 % 1 == 0) && (b4 != 0))
            if ((a4 / b4 == arr[0]) && (a4 * b4 == arr[2]) && (a4 >= 1) && (b4 >= 1) && (a4 <= 10000) && (b4 <= 10000))
            {
                cout << a4 << " " << b4 << endl;
                continue;
            }
        cout << "-1 -1" << endl;

*/