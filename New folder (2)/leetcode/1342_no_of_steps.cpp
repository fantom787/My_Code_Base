#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int helper(int num, int steps)
{
	if (num == 0)
	{
		return steps;
	}

	if (num % 2 == 0)
	{
		return helper(num / 2, steps + 1);
	}
	else
	{
		return helper(num - 1, steps + 1);
	}
	return steps;
}

int numberOfSteps(int num)
{
	int steps = 0;
	return helper(num, steps);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout<<numberOfSteps(8);

	return 0;
}