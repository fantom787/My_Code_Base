// (https://leetcode.com/problems/lucky-numbers-in-a-matrix/)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vi vec1)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << " ";
	}
	cout << endl;
}

bool isLucky(vector<vector<int>> matrix, int row, int coloumn)
{
	int n = matrix.size();
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][coloumn] > matrix[row][coloumn])
		{
			return false;
		}
	}
	return true;
}

int minInRow(vector<vector<int>> matrix, int row)
{
	int min = matrix[row][0];
	int index = 0;
	int n = matrix[0].size();
	for (int i = 0; i < n; i++)
	{
		if (matrix[row][i] < min)
		{
			min = matrix[row][i];
			index = i;
		}
	}
	return index;
}

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
	vector<int> ans;
	int n = matrix.size();
	int m = matrix[0].size();
	for (int i = 0; i < n; i++)
	{
		int mini = minInRow(matrix, i);
		if (isLucky(matrix, i, mini))
		{
			ans.push_back(matrix[i][mini]);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vvi vec1 = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
	display(luckyNumbers(vec1));
	return 0;
}