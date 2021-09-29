#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int search1(vector<int> arr, int target, int fir)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid, ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            if (fir == true)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return ans;
}
vector<int> first_last(vector<int> arr, int target)
{
    vector<int> ans;
    int start = search1(arr, target, 1);
    int end = search1(arr, target, 0);
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> ans = first_last(arr, 8);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}