#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int floor(vi arr, int target)
{
    int n = arr.size();
    int l = 0;
    if(target<=arr[l])
    {
        return -1;
    }
    int h = n - 1;
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        if (arr[mid] < target)
        {
            l = mid+1;
        }
        else if (arr[mid] >= target)
        {
            h = mid - 1;
        }
        mid = l + (h - l) / 2;
    }
    return arr[h];
}

int cieling(vi arr, int target)
{
    int n = arr.size();
    int l = 0;
    int h = n - 1;
    if(target>=arr[h])
    {
        return -1;
    }
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else if (arr[mid] > target)
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
        mid = l + (h - l) / 2;
    }
    return arr[l];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {4, 8, 9, 13, 15, 19, 21, 26, 28, 29};
    cout << floor(vec1, 15)<<endl;
    cout << cieling(vec1, 15);
    return 0;
}