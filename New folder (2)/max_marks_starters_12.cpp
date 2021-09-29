#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
	int a, b, c, x, y, z, ans = 0, temp;
	cin >> a >> b >> c >> x >> y >> z;
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{
				if ((i * a + j * b + k * c) <= 240)
				{
					temp = x * i + y * j + z * k;
					ans = max(ans, temp);
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--)
	{
		solve();
	}

	return 0;
}
/*

Cooking Examinations Authority (C.E.A.) is conducting an Ordinary Cooking Level (O.C.L.) test, which tests the candidate skills on three different aspects - Appearance, Flavor and Texture. Chef is planning to appear in this coveted test.

O.C.L. is a 240 minute test consisting of 20 problems on each aspect (and hence total 60 problems).

Chef figured out that for each problem on Appearance, Flavor and Texture

He requires A,B and C minutes respectively to correctly solve that problem.
He will be awarded X,Y and Z points respectively when correctly solved that problem.
Chef wonders what are the maximum points P that he can get in O.C.L.? Can you help the Chef?

Input Format
The first line of input contains a single integer T, denoting the number of testcases. The description of the T testcases follows.
The first line of each testcase contains 3 space separated integers A,B and C.
The second line of each testcase contains 3 space separated integers X,Y and Z.
Output Format
For each testcase, output a single line containing an integer P, which denotes the maximum points that the Chef can score in O.C.L.

Constraints
1≤T≤100
1≤A,B,C≤10
1≤X,Y,Z≤106
Sample Input 1 
3
4 4 4
5 5 5
5 5 5
10 8 6
5 6 7
5 6 7
Sample Output 1 
300
408
240
Explanation
Test Case 1: Chef can correctly solve all the problems within the time limit, resulting in total 300 points.

Test Case 2: Chef can correctly solve 20 problems on Appearance, 20 problems on Flavor and 8 problems on Texture, resulting in total 408 points. We can prove that the Chef cannot get more than 408 points.



*/