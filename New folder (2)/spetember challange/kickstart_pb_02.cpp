/*
ques. maxima find krna hai bahaut easy hai 2 min me krke dikhata hu
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
		cin >> arr[n];
	}
	if (n == 1)
	{
		cout << "1" << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 && arr[i] > arr[i + 1])
		{
			ans++;
		}
		if (i == n - 1 && arr[i] > arr[i - 1])
		{
			ans++;
		}
		if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}