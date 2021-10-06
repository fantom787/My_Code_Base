/*
is case me brute force kaam aa gya
dekho jonsa element tumhare d ke barabar aa rha hai usko 1 se increase kr do baki ke uske peeche ke elements ko 0 kr do
simple!!!
*/
#include <bits/stdc++.h>
using namespace std;

int isMin(int n, int d)
{
	int newN = n, rem, count = 0, c = 0;
	while (newN > 0)
	{
		rem = newN % 10;
		newN = newN / 10;
		c++;
		if (rem == d)
		{
			newN = newN * pow(10, c) + (rem + 1) * pow(10, c - 1);
			count = newN - n;
			c = 0;
			cout << newN << " newN  "
				 << "  count" << count << " " << c << endl;
		}
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, d;
		cin >> n >> d;
		cout << isMin(n, d) << endl;
	}
	return 0;
}
/*
You are given an integer N and a digit D. Find the minimum non-negetive integer you should add to N such that the final value of N does not contain the digit D.

Input Format
The first line contains T denoting the number of test cases. Then the test cases follow.
Each test case contains two integers N and D on a single line denoting the original number and the digit you need to avoid.
Output Format
For each test case, output on a single line the minimum non-negetive integer you should add to N.

Constraints
1≤T≤105
1≤N≤109
0≤D≤9
Subtasks
Subtask 1 (100 points): Original constraints
Sample Input 1 
5
21 5
8 8
100 0
5925 9
434356 3
Sample Output 1 
0
1
11
75
5644
Explanation
Test case 1: N=21 does not contain the digit D=5. Hence there is no need to add any integers to N.

Test case 2: If 1 is added to N=8, it becomes equal to 9, which does not contain the digit D=8.

Test case 3: The minimum integer you should add to N=100 such that the final value of N does not contain the digit D=0 is 11.

Test case 5: The minimum integer which is greater than 434356 and does not contain the digit D=3 is 440000. So we should add 440000−434356=5644.


*/