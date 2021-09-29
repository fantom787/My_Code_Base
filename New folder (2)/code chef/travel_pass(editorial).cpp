#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;

	string s;
	cin>>s;

	int ans = 0;

	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
			ans+=a;
		else
			ans+=b;
	}

	cout<<ans<<endl;
}

int32_t main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--)
		solve();

return 0;
}