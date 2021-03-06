// Author: Ambuj Kumar(fantom787)
//  If it works, don't touch it.
/*  All Links
 Youtube:  https://www.youtube.com/c/Fantom7877/videos
 Linkedin: https://www.linkedin.com/in/ambuj-kumar-88b614203/
 Codeforces: https://codeforces.com/profile/fantom787
 Codechef: https://www.codechef.com/users/ambuj787
*/

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
// #define endl "\n";
#define all(s) s.begin(), s.end()
#define pb push_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x) // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x) // gives the most significant bit of the number
#define sz(x) (int)x.size()
#define F first
#define S second
#define int long long
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define kickstart(x)                 \
    {                                \
        cout << "Case #" << x << ":" \
             << " ";                 \
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

int lcm(int a, int b)
{
    return ((ll)a * b) / gcd(a, b);
}
// modular exponentiation
int modpow(int x, int n, int m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = ((res % m) * (x % m)) % m;
        }
        x = ((x % m) * (x % m)) % m;
        n >>= 1;
    }
    return res;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}
// Get All The Divisors Of That Number
vector<int> getDiv(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            ans.pb(n / i);
        }
    }
    return ans;
}
// to get the prime factors of that number
vector<int> getprimefac(int n)
{
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                ans.pb(i);
            }
        }
    }
    return ans;
}
// to invert a binary string
void invert(string &s)
{
    int n = sz(s);
    for (int i = 0; i < n; i++)
    {
        s[i] ^= '0' ^ '1';
    }
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
// display a vector
void display(vector<int> a)
{
    cout << "Displaying Vector:" << endl;
    cout << a << endl;
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
// get instant prime
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = i * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined
/*/-----------------------------Code begins----------------------------------/*/

vector<int> dp(1000005);
void solve(int testcase)
{
    // kickstart(testcase);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    for (int i = 0; i <= k; i++)
    {
        if (i == 0)
        {
            dp[i] = 0;
        }
        else
        {
            int val = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i - a[j] >= 0)
                {
                    val = min(val, 1 + dp[i - a[j]]);
                }
            }
            dp[i] = val;
        }
    }
    cout << (dp[k] == INT_MAX ? -1 : dp[k]) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // seive();
    // seev();
    int n = 1;
    // cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    return 0;
}
/* stuff you should look for
 *
 * 0 0 n  try kr lo if multiple ans ka case hai to ya isse similar kuch hai to
 * i>j wale sare chahiye to prefix wala lga do sir jisme curr ko calc kro prev se and fir usko map kr do
 * a+b = a^b + 2*a&b
 * special cases (n=1?)/ odd/even index
 * sir square wala bhi soch lo
 * consecutive elements ka scene hai to genedy apraoch lga do sir
 * follow the basics koi nya try kr rha hai toh uske primitive try kr
 * XOR --> ALWAYS TRY 45132
 */