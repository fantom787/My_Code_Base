struct AugumentedDsu
{
    int n;
    int comp;
    vector<int> siz, lable, nedges, potential, parent;
    vector<vector<vector<int>>> edges;

    void init(int rn)
    {
        n = rn;
        siz = vector<int>(n, 1);
        potential = vector<int>(n);
        lable = vector<int>(n);
        edges = vector<vector<vector<int>>>(n);
        iota(lable.begin(), lable.end(), 0ll);
        edges = vector<vector<vector<int>>>(n);
        comp = n;
    }

    void relable(int node, int target, int add)
    {
        if (lable[node] == target)
            return;

        lable[node] = target;
        potential[node] = add;
        for (auto it : edges[node])
            relable(it[0], target, add + it[1]);
    }

    bool merge(int u, int v, int d)
    {
        int lu = lable[u], lv = lable[v];
        if (lu == lv)
        {
            // adding a edge from u-->v so u will be above and v will be below
            return (potential[v] - potential[u] == d);
        }
        edges[u].pb({v, d});
        edges[v].pb({u, -d});
        if (siz[lu] < siz[lv])
        {
            swap(lu, lv);
            swap(u, v);
            d *= -1;
        }
        siz[lu] += siz[lv];
        siz[lv] = 0;
        relable(v, lable[u], potential[u] + d);
        return 1;
    }

    int findPar(int n) { return lable[n]; }
};
/**
 *
 *          Application:- used for maintaining a system of equations of the form ( y-x = d ) along
 *                        with  their consistencial queries dynamically using disjoint set union and
 *                        find data structure.
 *
 *
 *          reference : https://medium.com/@alphawizard/augmented-dsu-f2c974926cb2
 *          problem : https://atcoder.jp/contests/abc328/tasks/abc328_f
 *
 *
 *
 *
 */