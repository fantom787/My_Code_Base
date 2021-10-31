#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool sorted(vector<int> arr, int index)
{
	if (index == arr.size()-1)
	{
		return true;
	}
	return (arr[index] < arr[index + 1]) && sorted(arr, index + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> arr = {1, 2, 3, 4, 5, 9, 7, 8, 9};
	cout << sorted(arr, 0);

	return 0;
}