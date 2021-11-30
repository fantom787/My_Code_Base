// [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<int> searchRange(vector<int> &nums, int target)
{
	vector<int> ans;
	if (!binary_search(nums.begin(), nums.end(), target))
	{
		ans.push_back(-1);
		ans.push_back(-1);
		return ans;
	}
	else
	{
		ans.push_back((lower_bound(nums.begin(), nums.end(), target) - nums.begin()));
		ans.push_back((upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vi vec1 = {5, 7, 7, 8, 8, 10};

	return 0;
}