vector<vector<int>> tree(4 * n + 10);
auto build = [&](int node, int start, int end, auto &&build) -> void
{
    if (start == end)
    {
        tree[node].pb(p[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid, build);
    build(node * 2 + 1, mid + 1, end, build);
    tree[node] = vector<int>(sz(tree[2 * node]) + sz(tree[2 * node + 1]));
    merge(all(tree[2 * node]), all(tree[2 * node + 1]), tree[node].begin());
};

auto query = [&](int node, int start, int end, int l, int r, int qNode, auto &&query) -> bool
{
    if (r < start || l > end)
    {
        // change this
        return 0;
    }
    if (start >= l && end <= r)
    {
        // change this
        int s = tin[qNode], e = tout[qNode];
        auto lb = lower_bound(all(tree[node]), s);
        if (lb != tree[node].end())
        {
            return (*lb) < e;
        }
        return 0;
    }
    int mid = (start + end) / 2;
    // change this
    int ans = query(2 * node, start, mid, l, r, qNode, query) || query(2 * node + 1, mid + 1, end, l, r, qNode, query);
    return ans;
};
/*https://codeforces.com/contest/1899/submission/233918001*/