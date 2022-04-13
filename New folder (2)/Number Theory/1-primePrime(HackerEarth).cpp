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
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcdX(int a, int b, int &x, int &y) // gcd extended
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
    return ((ll)a * b) / gcd(a, b);
}
// modular exponentiation
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

void display(vector<int> vec)
{
    cout << "Displaying Vec" << endl;
    for (auto it : vec)
    {
        cout << it << " ";
    }
    cout << endl;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

// prime numbers upto 90million
bool isp[90000001];
vector<int> prime; // holds all prime numbers upto 90 million
void seev()
{
    int maxN = 90000000;
    isp[0] = isp[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!isp[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isp[j] = true;
            }
        }
    }
    for (int i = 2; i <= maxN; i++)
    {
        if (!isp[i])
        {
            prime.push_back(i);
        }
    }
}

// factors of that number upto 10^6
// smallest and largest prime numbers upto 10^6
vector<bool> isPrime(1e6 + 1, 1);
vector<int> smallestPrimeFactor(1e6 + 1, 1e9); // at the ith value stores the smallest factor of that number
vector<int> largestPrimeFactor(1e6 + 1, -1);   // at the ith value stores the smallest factor of that number
void seive()
{
    isPrime[0] = isPrime[1] = false;
    isPrime[2] = true;
    for (int i = 2; i <= 1e6; i++)
    {
        if (!isPrime[i])
            continue;
        smallestPrimeFactor[i] = i;
        largestPrimeFactor[i] = i;
        for (int j = i; j <= 1e6; j += i)
        {
            isPrime[j] = false;
            smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i);
            largestPrimeFactor[j] = max(largestPrimeFactor[j], i);
        }
    }
}

vector<bool> ar(1000001, true);
vector<int> pp(1000001);
void s()
{
    int maxN = 1000001;
    ar[0] = ar[1] = false;
    for (ll i = 2; i * i < maxN; i++)
    {
        if (ar[i])
        {
            for (ll j = i * i; j < maxN; j += i)
            {
                ar[j] = false;
            }
        }
    }
    ll cnt = 0;
    for (ll i = 1; i < maxN; i++)
    {
        if (ar[i])
            cnt++;
        if (ar[cnt])
        {
            pp[i] = 1;
        }
    }
    for (ll i = 1; i < maxN; i++)
    {
        pp[i] += pp[i - 1];
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    int cnt = pp[r]-pp[l-1];
    // for (int i = l; i < r + 1; i++)
    // {
    //     if (pp[i])
    //         cnt++;
    // }
    cout << cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    s();
    // seive();
    // seev();
    int n = 1;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}