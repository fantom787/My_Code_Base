// bruteforce --> not accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int prime_number(int n)
{
	int prime = 0;
	if (n == 1)
	{
		prime = 2;
	}
	else if (n == 2)
	{
		prime = 3;
	}
	else if (n % 2 == 0)
	{
		prime = pow((n / 2), 2) + (n / 2 + 1);
	}
	else if (n % 2 != 0)
	{
		prime = pow(((n / 2) + 1), 2) + (n / 2);
	}
	return prime;
}

void solve()
{
	int a, b, x = 0;
	cin >> a >> b;
	int min1 = min(a, b);
	for (int i = 1; i < sqrt(min1); i++)
	{
		if (a % prime_number(i) == 0 && b % prime_number(i) == 0)
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO " << endl;
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
You are given two positive integers a and b. You also have a number x, which is initially set to 0. At first, you can add a to x any number of times. After that, you can divide x by b any number of times as long as x is divisible by b.

Print YES if you can make x equal to 1, otherwise print NO.

Input Format
First line of input will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line, two positive integers a,b.
Output Format
For each test case, output on one line YES if it is possible to make x , or NO if it is not possible to do so.

Output is case insensitive, which means that "yes", "Yes", "YEs", "no", "nO" - all such strings will be acceptable.

Constraints
1≤T≤100000
1≤a,b≤109
Sample Input 1 
4
3 10
9 6
7 30
8 12
Sample Output 1 
NO
YES
NO
YES
Explanation
Test case 2: We initially have x set to 0. Add a=9 to x for 4 times to make x equal to 36. And then divide x by b=6 for 2 times to make x equal to 1.

Test case 4: We initially have x set to 0. Add a=8 to x for 18 times to make x equal to 144. And then divide x by b=12 for 2 times to make x equal to 1.
*/