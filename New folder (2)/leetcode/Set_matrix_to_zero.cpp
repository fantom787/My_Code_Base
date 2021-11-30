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
	int low = lower_bound(nums.begin(), nums.end(), target);
	ans.push_back(low);
	int high = upper_bound(nums.begin(), nums.end(), target);
	ans.push_back(high);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	return 0;
}