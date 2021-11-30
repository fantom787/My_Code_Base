// https://leetcode.com/problems/product-of-array-except-self/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin() , x.end()

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<int> productExceptSelf(vector<int> &nums)
{
	int n = nums.size();
	int num = 1;
	vector<int> ans(n, 1);
	for (int i = 0; i < n; i++)
	{
		num *= nums[i];
		ans[i] = num;
	}
	num = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
		{
			ans[i] = ans[i - 1];
			num *= nums[i];
		}
		else if (!i)
		{
			ans[i] = num;
		}
		else
		{
			ans[i] = ans[i - 1] * num;
			num *= nums[i];
		}
	}

	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
      
     return 0;
}