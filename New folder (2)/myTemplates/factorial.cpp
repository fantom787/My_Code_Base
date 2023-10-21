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
const int factN = 100005; // change this according to the need
int fact[factN];
int inv_fact[factN];
void preNCR()
{
    fact[0] = 1;
    fact[1] = 1;
    inv_fact[0] = inv_fact[1] = modinv(1);
    for (int i = 2; i < factN; i++)
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