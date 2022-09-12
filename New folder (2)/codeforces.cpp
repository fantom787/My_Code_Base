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
int modpow(int x, int n)
{
	if (x == 0 && n == 0)
		return 0; // undefined case
	int res = 1;
	while (n)
	{
		if (n & 1)
		{
			res *= x;
		}
		x *= x;
		n >>= 1;
	}
	return res;
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
			if (n / i != i)
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
vector<int> sieve(int n)
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
// -------------------------------Mod-Int---Template-------------------------//
// const int mod = 998244353;
const int mod = 1000000007;
template <const int MOD>
struct modular_int
{
	int x;
	static vector<int> inverse_list;
	const static int inverse_limit;
	const static bool is_prime;
	modular_int()
	{
		x = 0;
	}
	template <typename T>
	modular_int(const T z)
	{
		x = (z % MOD);
		if (x < 0)
			x += MOD;
	}
	modular_int(const modular_int<MOD> *z)
	{
		x = z->x;
	}
	modular_int(const modular_int<MOD> &z)
	{
		x = z.x;
	}
	modular_int operator-(const modular_int<MOD> &m) const
	{
		modular_int<MOD> U;
		U.x = x - m.x;
		if (U.x < 0)
			U.x += MOD;
		return U;
	}
	modular_int operator+(const modular_int<MOD> &m) const
	{
		modular_int<MOD> U;
		U.x = x + m.x;
		if (U.x >= MOD)
			U.x -= MOD;
		return U;
	}
	modular_int &operator-=(const modular_int<MOD> &m)
	{
		x -= m.x;
		if (x < 0)
			x += MOD;
		return *this;
	}
	modular_int &operator+=(const modular_int<MOD> &m)
	{
		x += m.x;
		if (x >= MOD)
			x -= MOD;
		return *this;
	}
	modular_int operator*(const modular_int<MOD> &m) const
	{
		modular_int<MOD> U;
		U.x = (x * 1ull * m.x) % MOD;
		return U;
	}
	modular_int &operator*=(const modular_int<MOD> &m)
	{
		x = (x * 1ull * m.x) % MOD;
		return *this;
	}
	template <typename T>
	friend modular_int operator+(const T &l, const modular_int<MOD> &p)
	{
		return (modular_int<MOD>(l) + p);
	}
	template <typename T>
	friend modular_int operator-(const T &l, const modular_int<MOD> &p)
	{
		return (modular_int<MOD>(l) - p);
	}
	template <typename T>
	friend modular_int operator*(const T &l, const modular_int<MOD> &p)
	{
		return (modular_int<MOD>(l) * p);
	}
	template <typename T>
	friend modular_int operator/(const T &l, const modular_int<MOD> &p)
	{
		return (modular_int<MOD>(l) / p);
	}

	int value() const
	{
		return x;
	}

	modular_int operator^(const modular_int<MOD> &cpower) const
	{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		int power = cpower.x;

		if (curr.x <= 1)
		{
			if (power == 0)
				curr.x = 1;
			return curr;
		}
		while (power > 0)
		{
			if (power & 1)
			{
				ans *= curr;
			}
			power >>= 1;
			if (power)
				curr *= curr;
		}
		return ans;
	}

	modular_int operator^(long long power) const
	{
		modular_int<MOD> ans;
		ans.x = 1;
		modular_int<MOD> curr(this);
		if (curr.x <= 1)
		{
			if (power == 0)
				curr.x = 1;
			return curr;
		}
		// Prime Mods
		if (power >= MOD && is_prime)
		{
			power %= (MOD - 1);
		}

		while (power > 0)
		{
			if (power & 1)
			{
				ans *= curr;
			}
			power >>= 1;
			if (power)
				curr *= curr;
		}
		return ans;
	}

	template <typename T>
	modular_int &operator^=(T power)
	{
		modular_int<MOD> res = (*this) ^ power;
		x = res.x;
		return *this;
	}

	template <typename T>
	modular_int pow(T x)
	{
		return (*this) ^ x;
	}

	pair<long long, long long> gcd(const int a, const int b) const
	{
		if (b == 0)
			return {1, 0};
		pair<long long, long long> c = gcd(b, a % b);
		return {c.second, c.first - (a / b) * c.second};
	}

	inline void init_inverse_list() const
	{

		vector<int> &dp = modular_int<MOD>::inverse_list;
		dp.resize(modular_int<MOD>::inverse_limit + 1);
		int n = modular_int<MOD>::inverse_limit;
		dp[0] = 1;
		if (n > 1)
			dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			dp[i] = (dp[MOD % i] * 1ull * (MOD - MOD / i)) % MOD;
		}
	}
	modular_int<MOD> get_inv() const
	{
		if (modular_int<MOD>::inverse_list.size() < modular_int<MOD>::inverse_limit + 1)
			init_inverse_list();

		if (this->x <= modular_int<MOD>::inverse_limit)
		{
			return modular_int<MOD>::inverse_list[this->x];
		}
		pair<long long, long long> G = gcd(this->x, MOD);
		return modular_int<MOD>(G.first);
	}
	modular_int<MOD> operator-() const
	{
		modular_int<MOD> v(0);
		v -= (*this);
		return v;
	}
	modular_int operator/(const modular_int<MOD> &m) const
	{
		modular_int<MOD> U(this);
		U *= m.get_inv();
		return U;
	}
	modular_int &operator/=(const modular_int<MOD> &m)
	{
		(*this) *= m.get_inv();
		return *this;
	}
	bool operator==(const modular_int<MOD> &m) const
	{
		return x == m.x;
	}

	bool operator<(const modular_int<MOD> &m) const
	{
		return x < m.x;
	}

	template <typename T>
	bool operator==(const T &m) const
	{
		return (*this) == (modular_int<MOD>(m));
	}

	template <typename T>
	bool operator<(const T &m) const
	{
		return x < (modular_int<MOD>(m)).x;
	}
	template <typename T>
	bool operator>(const T &m) const
	{
		return x > (modular_int<MOD>(m)).x;
	}
	template <typename T>
	friend bool operator==(const T &x, const modular_int<MOD> &m)
	{
		return (modular_int<MOD>(x)).x == m.x;
	}
	template <typename T>
	friend bool operator<(const T &x, const modular_int<MOD> &m)
	{
		return (modular_int<MOD>(x)).x < m.x;
	}
	template <typename T>
	friend bool operator>(const T &x, const modular_int<MOD> &m)
	{
		return (modular_int<MOD>(x)).x > m.x;
	}

	friend istream &operator>>(istream &is, modular_int<MOD> &p)
	{
		int64_t val;
		is >> val;
		p.x = (val % MOD);
		if (p.x < 0)
			p.x += MOD;
		return is;
	}
	friend ostream &operator<<(ostream &os, const modular_int<MOD> &p) { return os << p.x; }
};

using mint = modular_int<mod>;
template <const int MOD>
vector<int> modular_int<MOD>::inverse_list;
template <const int MOD>
const int modular_int<MOD>::inverse_limit = -1;
template <const int MOD>
const bool modular_int<MOD>::is_prime = true;
template <> //-> useful if computing inverse fact = i_f[i-1] / i;
const int modular_int<mod>::inverse_limit = 200005;

const int N = 200005;
mint fact[N];
mint inv_fact[N];

void preNCR()
{
	fact[0] = 1;
	inv_fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i;
		inv_fact[i] = inv_fact[i - 1] / i;
	}
}

mint ncr(int n, int r)
{
	if (n < r)
	{
		return 0;
	}
	mint ans = fact[n];
	ans *= inv_fact[r];
	ans *= inv_fact[n - r];
	return ans;
}

mint npr(int n, int r)
{
	if (n < r)
	{
		return 0;
	}
	mint ans = fact[n] * inv_fact[n - r];
	return ans;
}

// -------------------------------Mod-Int---Template-------------------------//

// Flags to use: -std=c++17 -O2 -DLOCAL_PROJECT -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined

// Directions
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/*/-----------------------------Code begins----------------------------------/*/
// question padh lo sir pls
// constraints bhi dekh lo sir pls
void solve(int testcase)
{
	// kickstart(testcase);
	// debug(testcase);
	cout << fact[6] << endl;
}

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
	cin >> n;
	preNCR();
	for (int i = 1; i <= n; i++)
	{
		solve(i);
	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	// cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
	return 0;
}
