#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int *find_in_2d_array(int arr[], int target)
{
	int n = 3;
	int m = 5;
	// n--> row
	// m-->coloumn
	int row = 0;
	int coloumn = m - 1;
	while (row < n && coloumn >= 0)
	{
		if (arr[row][coloumn] == target)
		{
			return new int[2]{row, coloumn};
		}
		else if (arr[row][coloumn] > target)
		{
			coloumn--;
		}
		else if (arr[row][coloumn] < target)
		{
			row++;
		}
	}
	return new int[2]{-1, -1};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[3][5] = {{2, 4, 6, 8, 10},
					 {3, 6, 9, 12, 15},
					 {4, 8, 12, 16, 20}};
	int *ans = find_in_2d_array(arr, 3, 5, 10);
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}