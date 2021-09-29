/*
	bahut hi mst concept hai
	dekho array create kr lo aur sare elements ko 0 kr do
	fir kya kro ki 2 se start kro aur uske multiples  ko  1 kr do
	last me jo bachega wo prime no hoga

*/
#include <bits/stdc++.h>
using namespace std;

void prime_no(int n)
{
	int arr[n] = {0};
	for (int i = 2; i < n; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * i; j < n; j += i)
			{
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i < n; i++)
	{
		if (arr[i]==0)
		{
			cout<<i<<" ";
		}
		
	}
	
}

int main()
{
	int n = 1000 ; 
	prime_no(n);

	return 0;
}