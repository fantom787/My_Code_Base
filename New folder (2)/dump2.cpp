const int INF = 1e18;
const int N = 1e5 + 5;

const int32_t maxn = N;
// things that need to be changed
struct node
{
	int v = 0;
	node() {}
	node(int val)
	{
		v = 1 << (val - 'a');
	}
	void merge(node &l, node &r)
	{
		v = l.v | r.v;
	}
} zero;
struct update
{
	int v = 0;
	update() {}
	update(int val)
	{
		v = val;
	}
	void combine(update &other)
	{
	}
	void apply(node &x)
	{
		x = v;
	}
} noop;
struct segtree
{
	node t[4 * maxn];
	bool lazy[4 * maxn];
	update upds[4 * maxn];
	void pushdown(int32_t v, int32_t tl, int32_t tr)
	{
		int32_t tm = (tl + tr) / 2;
		if (lazy[v])
		{
			apply(v * 2, tl, tm, upds[v]);
			apply(v * 2 + 1, tm + 1, tr, upds[v]);
			lazy[v] = 0;
			upds[v] = noop;
		}
	}
	void apply(int32_t v, int32_t tl, int32_t tr, update &val)
	{
		if (tl != tr)
		{
			lazy[v] = 1;
			upds[v].combine(val);
		}
		val.apply(t[v]);
	}
	template <typename T>
	void build(T a[], int32_t v, int32_t tl, int32_t tr)
	{
		if (tl == tr)
		{
			t[v] = a[tl];
			return;
		}
		else
		{
			int32_t tm = (tl + tr) / 2;
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v].merge(t[v * 2], t[v * 2 + 1]);
		}
	}
	node query(int32_t v, int32_t tl, int32_t tr, int l, int r)
	{
		if (l > tr || r < tl)
			return zero;
		if (l <= tl && tr <= r)
		{
			return t[v];
		}
		pushdown(v, tl, tr);
		int32_t tm = (tl + tr) / 2;
		node a, b, ans;
		a = query(v * 2, tl, tm, l, r);
		b = query(v * 2 + 1, tm + 1, tr, l, r);
		ans.merge(a, b);
		return ans;
	}
	void rupd(int32_t v, int32_t tl, int32_t tr, int l, int r, update &val)
	{
		if (l > tr || r < tl)
			return;
		if (l <= tl && tr <= r)
		{
			apply(v, tl, tr, val);
			return;
		}
		pushdown(v, tl, tr);
		int32_t tm = (tl + tr) / 2;
		rupd(v * 2, tl, tm, l, r, val);
		rupd(v * 2 + 1, tm + 1, tr, l, r, val);
		t[v].merge(t[v * 2], t[v * 2 + 1]);
	}

public:
	int len = maxn;
	void clear()
	{
		rep(i, 0, 4 * len)
		{
			t[i] = zero;
			lazy[i] = 0;
			upds[i] = noop;
		}
	}
	template <typename T>
	void build(T a[])
	{
		build(a, 1, 0, len - 1);
	}
	node query(int l, int r)
	{
		return query(1, 0, len - 1, l, r);
	}
	void rupd(int l, int r, update val)
	{
		rupd(1, 0, len - 1, l, r, val);
	}
} t;

char c[N];
void solve()
{
	int q;
	cin >> c >> q;
	t.build(c);
	rep(i, 0, q)
	{
		int k;
		cin >> k;
		if (k == 1)
		{
			int pos;
			char ch;
			cin >> pos >> ch;
			pos--;
			t.rupd(pos, pos, ch);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			cout << ppc(t.query(l, r).v) << "\n";
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#ifdef SEIVE
	seive();
#endif
#ifdef NCR
	init();
#endif
	int t = 1;
	// cin>>t;
	while (t--)
		solve();
	return 0;
}