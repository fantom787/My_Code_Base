#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// fn for searching the peak of the array 
// when the arrray contains the first increasing elements and then decreasing elements
int binary_search(vector<int> arr)
{
    int l = 0, h = arr.size(), mid;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        // for the element lying in the increasing half of the array
        else if (arr[mid] < arr[mid + 1])
        {
            l = mid + 1;
        }
        // for the element lying in the decreasing half of the array
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}
// 2 3 4 6 9 12 11 8 6 4 1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> vec1 = {2, 3, 4, 6, 9, 12, 11, 8, 6, 4, 1};
    cout << binary_search(vec1) << endl;

    return 0;
}