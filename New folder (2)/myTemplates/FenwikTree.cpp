struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void update(int idx, int delta) // update
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

/*
https://codeforces.com/contest/1354/problem/D
*/