struct FWA
{
    int n;
    vector<vector<int>> mat, nc;
    void init(int rn)
    {
        n = rn;
        mat = vector<vector<int>>(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
    }
    void edge(int u, int v, int w)
    {
        mat[u][v] = min(w, mat[u][v]);
        mat[v][u] = min(w, mat[v][u]);
    }
    void run()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][k] == INF || mat[k][j] == INF)
                    {
                        continue;
                    }
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (mat[i][i] < 0)
            {
                nc.pb(i);
            }
        }
    }
};