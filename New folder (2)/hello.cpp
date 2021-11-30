#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool canJump(vector<int> &nums)
{

	int n = nums.size();
	int can_reach = 0;
	for (int i = 0; i <= can_reach; i++)
	{
		if (i == n - 1)
		{
			return true;
		}
		can_reach = max(can_reach, nums[i] + i);
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vi vec1 = {2, 0, 0};
	cout << canJump(vec1);
	return 0;
}