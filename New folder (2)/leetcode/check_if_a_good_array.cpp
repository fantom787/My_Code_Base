// 3. [Good Array](https://leetcode.com/problems/check-if-it-is-a-good-array/)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool isGoodArray(vector<int> &nums)
{
	int n = nums.size();
	int gcd;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			gcd = nums[i];
		else
		{
			gcd = _Gcd(gcd, nums[i]);
		}
	}
	if (gcd == 1)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	return 0;
}