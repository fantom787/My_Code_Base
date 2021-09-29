#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;

	if(((a+b)<=d && c<=e) || ((a+c)<=d && b<=e) || ((c+b)<=d && a<=e))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
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