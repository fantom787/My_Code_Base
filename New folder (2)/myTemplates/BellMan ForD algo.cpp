struct BFA
{
    int n;
    vector<array<int, 3>> ed;
    vector<int> dists;
    void init(int rn, vector<array<int, 3>> edges);
    {
        n = rn;
        ed = edges;
        dists = vector<int>(n, INF);
    }
    void edge(int u, int v, int w)
    {
        ed.pb({u, v, w});
    }
    void run(int node)
    {
        for (int i = 0; i < n; i++)
        {
            for (auto it : ed)
            {
                int u = it[0] - 1, v = it[1] - 1, w = it[2];
                dists[v] = min(dists[v], dists[u] + w);
            }
        }
    }
};
