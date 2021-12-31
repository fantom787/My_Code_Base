#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;

int piviot(vi vec1)
{
    int n = vec1.size();
    int l = 0;
    int h = n - 1;
    int mid = l + (h - l) / 2;
    while (l < h)
    {
        if (vec1[mid] > vec1[mid + 1])
        {
            return mid;
        }
        else if (vec1[mid] < vec1[mid - 1])
        {
            return mid - 1;
        }
        else if (vec1[mid] < vec1[l])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        mid = l + (h - l) / 2;
    }
    return mid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {11, 13, 15, 17};
    cout << piviot(vec1);
    return 0;
}