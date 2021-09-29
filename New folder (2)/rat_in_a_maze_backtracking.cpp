/*
	rat in a maze 
	
*/
#include <bits/stdc++.h>
using namespace std;

bool can_move(int **arr, int x, int y, int n)
{
	if (x < n && y < n && arr[x][y] == 1)
	{
		return true;
	}
	return false;
}
bool rat_in_a_maze(int **arr, int x, int y, int n, int **sloarr)
{
	if ((x == (n - 1)) && (y == (n - 1)))
	{
		sloarr[x][y] = 1;
		return true;
	}

	if (can_move(arr, x, y, n))
	{
		sloarr[x][y] = 1;
		if (rat_in_a_maze(arr, x + 1, y, n, sloarr))
		{
			return true;
		}
		if (rat_in_a_maze(arr, x, y + 1, n, sloarr))
		{
			return true;
		}
		sloarr[x][y] = 0;
		return false;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int **solarr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		solarr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			solarr[i][j] = 0;
		}
	}
	cout << endl;
	if (rat_in_a_maze(arr, 0, 0, n, solarr))
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << solarr[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

*/