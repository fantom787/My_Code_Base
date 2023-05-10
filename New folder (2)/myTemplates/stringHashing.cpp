vector<int> mod = {MOD, 998244353};
auto hash = [&](string s) -> vector<int>
{
    vector<int> ans(sz(mod));
    vector<int> p(sz(mod), 1);
    int n = sz(s);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sz(mod); j++)
        {
            ans[i] += (s[i] - 'a' + 1) * p[i];
            ans[i] %= mod[i];
            p[i] *= 31;
            p[i] %= mod[i];
        }
    }
    return ans;
};