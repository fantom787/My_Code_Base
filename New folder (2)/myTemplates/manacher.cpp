struct manacher
{
    vector<int> p;
    int n;
    void run_man(string s)
    {
        n = sz(s);
        p.assign(n, 1);
        for (int i = 1, l = 1, r = 1; i < n; i++)
        {
            p[i] = max(0ll, min(r - i, p[l + r - i]));
            while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    void build(string s)
    {
        string t;
        for (auto it : s)
        {
            t += string("#") + it;
        }
        run_man(t + "#");
    }
    // aba -->#a#b#a#
    int getlongest(int cen, bool odd)
    {
        int pos = 2 * cen + odd + 1 + (!odd);
        return p[pos] - 1;
    }
    bool checkPal(int l, int r)
    {
        if ((r - l + 1) <= getlongest((r + l) / 2, l % 2 == r % 2))
        {
            return 1;
        }
        return 0;
    }
};

// tested here ->
// https://cses.fi/problemset/task/1111