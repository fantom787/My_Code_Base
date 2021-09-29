/*
find in arrray whose size is not given
or
find an element in infinte array
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findIninfiniteArray(vector<int> vec1, int target)
{
    int start = 0;
    int end = 1;
    while (vec1[end] < target)
    {
        int newstart = end + 1;
        end = end + (end - start + 1) * 2;
        start = newstart;
    }
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec1[mid] < target)
        {
            start = mid + 1;
        }
        else if (vec1[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "start" << endl;
    vector<int> vec1 = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    cout << findIninfiniteArray(vec1, 10);

    return 0;
}