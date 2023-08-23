
// Dsu by Galen Colin preffered
/* union by size */
struct dsu
{
    int n;
    int comp;
    vector<int> siz, lable, nedges;
    vector<vector<int>> edges;

    void init(int rn)
    {
        n = rn;
        siz = vector<int>(n, 1);
        lable = vector<int>(n);
        nedges = vector<int>(n);
        iota(lable.begin(), lable.end(), 0ll);
        edges = vector<vector<int>>(n);
        comp = n;
    }

    void relable(int node, int target)
    {
        if (lable[node] == target)
            return;

        lable[node] = target;

        for (int it : edges[node])
            relable(it, target);
    }

    bool merge(int u, int v)
    {
        edges[u].push_back(v);
        edges[v].push_back(u);
        nedges[lable[u]]++;
        if (lable[u] == lable[v])
            return 0;

        if (siz[lable[u]] > siz[lable[v]])
            swap(u, v);

        siz[lable[v]] += siz[lable[u]];
        siz[lable[u]] = 0;
        nedges[lable[v]] += nedges[lable[u]];
        relable(u, lable[v]);
        comp--;
        return 1;
    }

    int findPar(int n) { return lable[n]; }
};

// Dsu BY kalsh Gupta-- kal013
/*
    HOW TO INITALIZE
    https://codeforces.com/contest/1559/status/D1?friends=on here u can find more
    FIRST CREATE A OBJECT
    THEN INITILAIZE IT WITH INIT FN

    THE IF U WANT TO MERGER THE USE FN MERGE

    COMP WILL GIVE U THE NUMBER OF COMPONENTS

    FIND FN WILL FIND THE PARENT OF THAT NODE

    EXAMPLE
    DSU t1;

    t1.init(n); --> it is used to initialze the dsu
    int u,int v;
    cin>>u>>v;
    t1.merge(u,v);--> will merge the  edges

    int size of component -> t1.comp; --> return total number of components;

    int par = t1.find(u);-->return the parent of the u

*/
const int N = 1e5 + 10;
struct DSU
{
    int dsu[N];
    int comp;
    void init(int n)
    {
        for (int i = 1; i <= n; ++i)
            dsu[i] = -1;
        comp = n;
    }
    int Find(int n)
    {
        return (dsu[n] < 0) ? n : dsu[n] = Find(dsu[n]);
    }

    bool Merge(int x, int y)
    {
        x = Find(x);
        y = Find(y);

        if (x == y)
            return false;

        if (dsu[x] > dsu[y])
            swap(x, y);

        dsu[x] += dsu[y];
        dsu[y] = x;
        --comp;
        return true;
    }
};
