#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int rotated_binary_search(vi vec1, int target, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int mid = start + (end - start) / 2;
	if (vec1[mid] == target)
	{
		return mid;
	}
	// if i m in the 1st half then to check it in which half i m --> mid>start
	// now i will check wheather my target lies in the range of start and mid or not
	// for that i will check target>start & target<mid
	// then i will search in that sorted array
	else if (vec1[mid] >= vec1[start])
	{
		if (target >= vec1[start] && target < vec1[mid])
		{
			return rotated_binary_search(vec1, target, start, mid - 1);
		}
		else
		{
			return rotated_binary_search(vec1, target, mid + 1, end);
		}
	}
	// if i m in the second half then to check it in which half i m -->mid<end
	// now check wheather my target lies in that range or not
	// for that i will check target>mid & target<end
	// then i will search in that sorted array
	else if (vec1[mid] <= vec1[end])
	{
		if (target > vec1[mid] && target <= vec1[end])
		{
			return rotated_binary_search(vec1, target, mid + 1, end);
		}
		else
		{
			return rotated_binary_search(vec1, target, start, mid - 1);
		}
	}
	// now the only case left is that my target is after the mid and before the piviot of the rotation
	// so put it in the else statement as it is the last case left
	return rotated_binary_search(vec1, target, start, mid - 1);
}
// 5 6 7 8 9 1 2 3
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vi vec1 = {5, 6, 7, 8, 9, 1, 2, 3, 4};
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << rotated_binary_search(vec1, vec1[i], 0, vec1.size() - 1)<<" ";
	}

	return 0;
}