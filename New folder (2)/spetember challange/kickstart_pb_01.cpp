/*
 Que. aisa program likho jo longest subarray ki length btaye jinka diffrence same ho
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ans = 2;
	int pd = arr[1] - arr[0];
	int c_ans = 2;

	for (int i = 2; i < n; i++)
	{
		if (pd == arr[i] - arr[i - 1])
		{
			c_ans += 1;
		}
		else
		{
			pd = arr[i] - arr[i - 1];
			c_ans = 2;
		}
		ans = max(ans, c_ans);
	}
	cout << ans;
	return 0;
}