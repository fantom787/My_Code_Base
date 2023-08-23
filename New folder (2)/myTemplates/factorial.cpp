// ncr i.e number of combinations
const int factN = 100005;// change this according to the need
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