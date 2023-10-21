struct BFA
{
    int n;
    vector<array<int, 3>> ed;
    vector<int> dists, par;
    void init(int rn)
    {
        n = rn;
        dists = vector<int>(n, INF);
        par = vector<int>(n, -1);
    }
    void edge(int u, int v, int w)
    {
        ed.pb({u, v, w});
    }
    void run(int node)
    {
        dists[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (auto it : ed)
            {
                int u = it[0], v = it[1], w = it[2];
                if (dists[v] > dists[u] + w)
                {
                    dists[v] = min(dists[v], dists[u] + w);
                    par[v] = u;
                }
            }
        }
    }
    bool checkCycle()
    {
        for (auto it : ed)
        {
            int u = it[0], v = it[1], w = it[2];
            if (dists[v] > dists[u] + w)
            {
                return 1;
                dists[v] = min(dists[v], dists[u] + w);
                par[v] = u;
            }
        }
        return 0;
    }
    vector<int> findCycle()
    {
        int node = -1;
        for (auto it : ed)
        {
            int u = it[0], v = it[1], w = it[2];
            if (dists[v] > dists[u] + w)
            {
                node = v;
                break;
                dists[v] = min(dists[v], dists[u] + w);
                par[v] = u;
            }
        }
        for (int i = 0; i < n; i++)
        {
            node = par[node];
        }
        vector<int> ans;
        for (int i = node; !(sz(ans) >= 1 && i == node); i = par[i])
        {
            ans.pb(i + 1);
        }
        ans.pb(node + 1);
        reverse(all(ans));
        return ans;
    }
};