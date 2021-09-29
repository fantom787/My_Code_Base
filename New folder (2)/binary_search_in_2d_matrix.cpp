#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> find_in_2d_array(vector<vector<int>> vec1, int target)
{
    // n-->row
    // m-->coloumn
    int n = vec1.size();
    int m = vec1[0].size();
    int row = 0;
    int coloumn = m - 1;
    vector<int> ans = {-1, -1};

    while (row < n && coloumn >= 0)
    {
        if (vec1[row][coloumn] == target)
        {
            ans[0] = row;
            ans[1] = coloumn;
            return ans;
        }
        // in the last coloumn all the elements are gretest
        // so if it is smaller than it is smaller than all the elements in that coloumn
        // so coloumn is decreased by 1
        else if (vec1[row][coloumn] > target)
        {
            coloumn--;
        }
        // in first row all the elements are smaller than the rest so
        // if it is greater than that so it is greater than all the elements in that row
        // so row++
        else if (vec1[row][coloumn] < target)
        {
            row++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> vec1;
    vec1 = {{2, 4, 6, 8, 10},
            {3, 6, 9, 12, 15},
            {5, 10, 13, 16, 20}};
    int target = 13;
    vector<int> ans = find_in_2d_array(vec1, target);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}