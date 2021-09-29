/*
armstrong number   153 --> iske digits ke cude ka sum is number ke barabar hoga
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 153;
	int original_n = n;
	int sum = 0;
	while (n > 0)
	{
		int lastdigit = n % 10;
		sum += pow(lastdigit, 3);
		n /= 10;
	}

	if (sum == original_n)
	{
		cout << "it is a armstrong no " << endl;
	}

	return 0;
}