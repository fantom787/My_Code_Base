/*
    Author: Ambuj Kumar(fantom787)
    If it works, don't touch it.
----------------------All Links -------------------------
 Linkedin: https://www.linkedin.com/in/ambuj-kumar-88b614203/
 Codeforces: https://codeforces.com/profile/fantom787
 Codechef: https://www.codechef.com/users/ambuj787
*/

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// header files
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // for pbds
#include <ext/pb_ds/tree_policy.hpp>

// namespace
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

/* ordered set*/
template <class T, class cmp = less_equal<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/* ordered map*/
template <class key, class value, class cmp = less_equal<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
/* find_by_order(k)  returns iterator to kth element starting from 0;
 * order_of_key(k) returns count of elements strictly smaller than k;*/

/* min heap*/
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

// Constants
#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// macros
#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x) // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x) // gives the most significant bit of the number
#define sz(x) (int)x.size()
#define F first
#define acc(x) accumulate(all(x), 0ll)
#define S second
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
#define hi cout << "hi" << endl
#define NO cout << "NO" << endl
#define YES cout << "YES" << endl
// debug
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
void _print(int t)
{
    cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.F);
    cerr << ",";
    _print(p.S);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
    cerr << endl;
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
    cerr << endl;
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
    cerr << endl;
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
    cerr << endl;
}

// custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // Credits: https://codeforces.com/blog/entry/62393
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

// ncr i.e number of combinations
const int N = 100005;
int fact[N];
int inv_fact[N];
void preNCR()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
        inv_fact[i] = modinv(fact[i]);
    }
}
int ncr(int n, int r)
{
    if (n < r)
    {
        return 0;
    }
    int ans = fact[n];
    ans %= MOD;
    ans *= inv_fact[r];
    ans %= MOD;
    ans *= inv_fact[n - r];
    ans %= MOD;
    return ans;
}
int npr(int n, int r)
{
    if (n < r)
    {
        return 0;
    }
    int ans = fact[n];
    ans %= MOD;
    ans *= inv_fact[n - r];
    ans %= MOD;
    return ans;
}

/*--------------- Seive -----------------------*/
// Get All The Divisors Of That Number
vector<int> getdiv(int n)
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
// to invert a binary string
void invert(string &s)
{
    int n = sz(s);
    for (int i = 0; i < n; i++)
    {
        s[i] ^= '0' ^ '1';
    }
}

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

// Directions
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/*/-----------------------------Code begins----------------------------------/*/
void solve(int testcase)
{
    // kickstart(testcase);
    // debug(testcase);
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<int> dp(sum + 10);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = sum; s > 0; s--)
        {
            if (s - i >= 0)
            {
                dp[s] += dp[s - i];
                dp[s] %= MOD;
            }
        }
    }
    int ans = dp[sum];
    cout << (ans * modinv(2)) % MOD << endl;
    /*ez sol

     int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2)
    {
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<vector<int>> dp(n + 10, vector<int>(sum + 10));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            if (s - i >= 0)
            {
                dp[i][s] += dp[i - 1][s - i];
                dp[i][s] %= MOD;
            }
            dp[i][s] += dp[i - 1][s];
            dp[i][s] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[i][sum];
    }
    cout << (((dp[n][sum]) % MOD) * modinv(2)) % MOD << endl;



    */
}

/* stuff you should look for
 *    ------------------IMPORTANT-----------------------
 *    when u have to check that a bit is present in both the numbers after doing their xor then simply take and with the first number
 *    and take and with the not of second number as if the bit is present in both then theri xor will be zero so taking not will erase
 *    the set bits in b  and taking and with it prooves that this bit was not present in that number if both the ands are sane
 *    for more info u can look to the problem D of educational codeforces round 134
 *    in that problem what i did was i was checking for the jth bit is present in the xor of 2 numbers or not
 *    i simply did the above stated
 *
 *    ------------------IMPORTANT-----------------------
 * at 1 pe kya hoga wo case bhi soch lo
 * -------custom comparator to use in set or multiset or map or multimap--------
 *
 *      set<data_type,decltype(cmp)>name_of_the_set(cmp)
 *     here cmp is the custom comparator
 *
 * at 1 pe kya hoga wo case bhi soch lo
 * if u want to find the sum of diffrence for all possible 2 pairs its brute would be n^2
       but with some maths u can see that every diffrence is used in total number of its before edges and after edges
       i.e  diff*i*(n-1)
 * mod wala funda kaam na kre to prefix and suffix lga do
 * when u are not able to decide which one to remove then the answer is simply iterate and find the max/min answer for each index
 * if u have to make array increasing by adding 1 to subarray then sum of diffrences(which have to increased) is the answer
 * whenever i want to find the position of first number greater than
     my number then it is good to store all pos of first greater number in prefix
     ans this will help us to achieve our goal
 * sbse pehle question dobara padho sir
 *
 * about lambda function
 *          auto nameOFfunction = [&](what to pass , auto&& nameOFfunction)-> return type{
 *                                  body};
 *
 *
 * if u r multiplying and u have to find equal multipy then u can take 1st and last everytime
 * nlog(log(n)) bhi soch lo sir like jha multiples ka case aya wha pe seive of erathosthenisis ka concept lga do
 * a+b = a^b + 2*a&b
 * a+b = a|b + a&b
 * special cases (n=1?)/ odd/even index
 * sir square wala bhi soch lo
 * follow the basics koi nya try kr rha hai toh uske primitive try kr
 * XOR --> ALWAYS TRY 45132
 */
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    int n = 1;
    // cin >> n;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    // cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    return 0;
}
