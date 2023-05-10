struct euler
{
    vector<vector<int>> edges;
    int n;
    vector<int> in, out;
    vector<int> tour;
    int time = 0;
    void dfs(int node, int par)
    {
        in[node] = time++;
        tour.pb(node);
        for (auto it : edges[node])
        {
            if (it != par)
            {
                dfs(it, node);
            }
        }
        out[node] = time++;
        tour.pb(node);
    }
    euler(vector<vector<int>> e)
    {
        n = sz(e);
        edges = e;
        in = vector<int>(n);
        out = vector<int>(n);
        dfs(0, -1);
    }
};