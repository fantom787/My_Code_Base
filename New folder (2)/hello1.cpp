#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
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

int32_t main()
{
    cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    preNCR();
    cout << ncr(10, 5);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s " << endl;
    return 0;
}