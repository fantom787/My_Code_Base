struct segtree
{
    int n;
    vector<int> seg;
    void init(int s, vector<int> arr)
    {
        n = (ppcll(s) == 1 ? s : (1ll<<(msb(s) + 1)));
        seg = vector<int>(2 * n + 10);
        for (int i = 0; i < sz(arr); i++)
        {
            seg[i + n] = arr[i];
        }
        // change this according to the problem
        for (int i = n - 1; i >= 1; i--)
        {
            seg[i] = seg[2 * i] + seg[2 * i + 1];
        }
    }
    // update this according to the problem
    int find(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
        {
            return 0;
        }
        if (ql <= l && qr >= r)
        {
            return seg[node];
        }
        int mid = (l + r) / 2;
        // children of current node are 2*node , 2*node+1 --->according to the errictoo video on seg tree
        return find(2 * node, l, mid, ql, qr) + find(2 * node + 1, mid + 1, r, ql, qr);
    }
    int query(int l, int r)
    {
        return find(1, 0, n - 1, l, r);
    }
    // update this according to the problem
    // if there is range update then u can see the cses problem solution in which i have range update code also
    void update(int idx, int val)
    {
        int id = n + idx;
        seg[id] = val;
        for (int i = id / 2; i >= 1; i /= 2)
        {
            seg[i] = seg[2 * i] + seg[2 * i + 1];
        }
    }
};