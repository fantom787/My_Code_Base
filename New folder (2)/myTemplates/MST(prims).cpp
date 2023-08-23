struct MST
{
    int n;
    vector<vector<array<int, 2>>> edges;
    vector<int> par, vis;
    void init(int rn)
    {
        n = rn;
        edges = vector<vector<array<int, 2>>>(n);
        par = vector<int>(n);
        vis = vector<int>(n);
    }
    void run(int x = 0)
    {
        min_heap<vector<int>> pq;
        pq.push({0, x, -1});
        while (sz(pq))
        {
            auto tp = pq.top();
            pq.pop();
            int dis = tp[0], node = tp[1], p = tp[2];
            if (vis[n])
            {
                continue;
            }
            vis[n] = 1;
            par[n] = p;
            for (auto it : edges[n])
            {
                pq.push({it[1], it[0], n});
            }
        }
    }
};