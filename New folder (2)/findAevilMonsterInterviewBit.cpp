#include <bits/stdc++.h>
using namespace std;
#define Inf 1000000000000
#define mod 1000000007
#define sz 200005
#define nline '\n'
#define pb push_back
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
typedef long long int ll;

class fenwicktree
{

public:
	ll size;
	vector<ll> BITTree;
	fenwicktree(ll n)
	{
		BITTree.assign(n + 1, 0);
		size = n;
	}

	ll getsum(ll i)
	{
		ll s = 0;
		i = i + 1;
		while (i > 0)
		{
			s += this->BITTree[i];
			i -= i & (-i);
		}

		return s;
	}

	ll query(ll l, ll r)
	{

		return this->getsum(r) - this->getsum(l - 1);
	}

	void update(ll i, ll v)
	{

		i += 1;
		while (i <= this->size)
		{
			this->BITTree[i] += v;
			i += i & (-i);
		}
	}
};

void answer()
{

	ll n, q;
	cin >> n >> q;

	vector<vector<ll>> a(n, vector<ll>(3, -1));

	for (ll i = 0; i < n; ++i)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	vector<vector<ll>> b(q, vector<ll>(2, -1));
	for (ll i = 0; i < n; ++i)
	{
		cin >> b[i][0] >> b[i][1];
	}

	vector<vector<ll>> start(sz, vector<ll>()), end(sz, vector<ll>());
	vector<vector<pair<ll, ll>>> query(sz, vector<pair<ll, ll>>());

	ll total = 0;
	set<ll> compress;
	for (ll i = 0; i < n; ++i)
	{
		start[a[i][0]].pb(a[i][2]);
		end[a[i][1] + 1].pb(a[i][2]);

		total += (a[i][1] - a[i][0] + 1);
		compress.insert(a[i][2]);
	}

	for (ll i = 0; i < q; ++i)
	{
		query[b[i][0]].pb({b[i][1], i});
		compress.insert(b[i][1]);
	}

	map<ll, ll> key;

	ll compressedValue = 0;
	for (auto &x : compress)
	{
		key[x] = compressedValue++;
	}

	fenwicktree f = fenwicktree(compressedValue + 1);
	vector<ll> dec(q, 0);
	for (ll i = 0; i < sz; ++i)
	{

		for (auto &x : start[i])
			f.update(key[x], 1);

		for (auto &x : end[i])
			f.update(key[x], -1);

		ll prevKey = 0;
		for (auto &x : query[i])
		{
			if (prevKey <= key[x.first])
			{
				dec[x.second] = f.query(prevKey, key[x.first]);
				prevKey = key[x.first] + 1;
			}
		}
	}

	vector<ll> ans(q, 0LL);
	for (ll i = 0; i < q; ++i)
	{
		total -= dec[i];
		ans[i] = total;
	}

	for (auto &x : ans)
		cout << x << ' ';

	cout << nline;
}

int main()
{
	fastio;

	int T = 1;
	for (int t = 1; t <= T; ++t)
	{
		answer();
	}

	return 0;
}