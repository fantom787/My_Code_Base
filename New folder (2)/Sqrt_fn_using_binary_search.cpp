// find sqrt using binary search
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// time complexity : O(log(n));
float sqroot(int n, int p)
{
	int s = 0;
	int e = p;
	int m;
	float root = 0.0;
	float p_temp = 0.1;
	while (s <= e)
	{
		m = s + (e - s) / 2;
		if (m * m == n)
		{
			root = m;
			break;
		}
		else if (m * m > n)
		{
			e = m - 1;
		}
		else if (m * m < n)
		{
			s = m + 1;
		}
	}
	for (int i = 0; i < p; i++)
	{
		while (root * root <= n)
		{
			root += p_temp;
		}
		root -= p_temp;
		p_temp /= 10;
	}
	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << sqroot(100, 6);
	return 0;
}