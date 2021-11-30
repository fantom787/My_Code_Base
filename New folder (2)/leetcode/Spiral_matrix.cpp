// [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
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
	for (auto it : vec1)
	{
		cout << it << " ";
	}
	cout << endl;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

	vector<int> ans;

	int m = matrix.size();		// number of rows
	int n = (matrix[0].size()); // number of columns
	const int matrix_size = m * n;

	int row = 0;
	int col = 0;

	while (1)
	{
		for (int i = col; i < n - col; i++)
		{
			ans.push_back(matrix[row][i]);
			printf("%d ", ans[ans.size() - 1]);
		}

		row++;
		if (ans.size() == matrix_size)
			break;

		for (int i = row; i <= m - row; i++)
		{
			ans.push_back(matrix[i][n - col - 1]);
		}

		if (ans.size() == matrix_size)
			break;

		for (int i = n - col - 2; i >= col; i--)
		{
			ans.push_back(matrix[m - row][i]);
		}

		if (ans.size() == matrix_size)
			break;

		for (int i = m - row - 1; i >= row; i--)
		{
			ans.push_back(matrix[i][col]);
		}
		col++;

		if (ans.size() == matrix_size)
			break;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vvi matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

	display(spiralOrder(matrix));
	return 0;
}