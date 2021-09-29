#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// this function will search in the provided row
vector<int> binary_search(vector<vector<int>> arr, int target, int row, int cStart, int cEnd)
{
    vector<int> ans = {-1, -1};
    while (cStart <= cEnd)
    {
        int mid = cStart + (cEnd - cStart) / 2;
        if (arr[row][mid] < target)
        {
            cStart = mid + 1;
        }
        else if (arr[row][mid] > target)
        {
            cEnd = mid - 1;
        }
        else
        {
            ans[0] = row;
            ans[1] = mid;
            return ans;
        }
    }
    return ans;
}

vector<int> search_in_2d_array(vector<vector<int>> matrix, int target)
{
    vector<int> ans = {-1, -1};
    int rows = matrix.size();
    int coloumn = matrix[0].size();
    // Edge case -->the given matrix can be of 1d also
    if (rows == 1)
    {
        return binary_search(matrix, target, 0, 0, coloumn - 1);
    }
    int rStart = 0;
    int rEnd = rows - 1;
    int cMid = (coloumn - 1) / 2;
    // now run the loop till 2 rows are remaining
    while (rStart < (rEnd - 1))
    {
        int mid = rStart + (rEnd - rStart) / 2;
        if (matrix[mid][cMid] == target)
        {
            ans[0] = mid;
            ans[1] = cMid;
            return ans;
        }
        else if (matrix[mid][cMid] < target)
        {
            rStart = mid;
        }
        else
        {
            rEnd = mid;
        }
    }
    // now we have 2 rows
    // chech weather the target is inthe middle element or not
    if (matrix[rStart][cMid] == target)
    // checking for start
    {
        ans[0] = rStart;
        ans[1] = cMid;
        return ans;
    }
    if (matrix[rStart + 1][cMid] == target)
    // checking for the end
    {
        ans[0] = rStart + 1;
        ans[1] = cMid;
        return ans;
    }
    // search in 1st half
    if (matrix[rStart][cMid - 1] >= target && target >= matrix[rStart][0])
    {
        return binary_search(matrix, target, rStart, 0, cMid - 1);
    }
    // search in 2nd half
    else if (matrix[rStart][cMid + 1] <= target && target <= matrix[rStart][coloumn - 1])
    {
        return binary_search(matrix, target, rStart, cMid + 1, coloumn - 1);
    }
    // search in 3rd half
    else if (matrix[rStart + 1][cMid - 1] >= target && target >= matrix[rStart + 1][0])
    {
        return binary_search(matrix, target, rStart + 1, 0, cMid - 1);
    }
    // search in 4th half
    else if (matrix[rStart + 1][cMid + 1] <= target && target <= matrix[rStart + 1][coloumn - 1])
    {
        return binary_search(matrix, target, rStart + 1, cMid + 1, coloumn - 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> vec1 = {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15, 16}};
    vector<int> ans = search_in_2d_array(vec1, 2);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}