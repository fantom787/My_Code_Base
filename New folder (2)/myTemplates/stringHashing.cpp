vector<int> mod = {MOD, 998244353};
auto stringhash = [&](string s, int MOD = MOD) -> int
{
    int p = 31, n = sz(s);
    vector<int> hash(n);
    hash[0] = (s[0] - 'a' + 1); // change accoding to the problem
    for (int i = 1; i < n; i++)
    {
        hash[i] += (hash[i - 1] + (s[i] - 'a' + 1) * p);
        hash[i] %= mod;
        p *= 31;
        p %= mod;
    }
    return hash[n - 1];
};
