#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool canRead(vector<int>arr,int m,int mid)
{
    int sumPage = 0;
    int count_student = 1;
    for(auto it:arr)
    {
        if(sumPage+it<=mid)
        {
            sumPage+=it;
        }
        else 
        {
            count_student++;
            if(count_student>m||it>mid)
            {
                return false;
            }
            sumPage=it;
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int l = 0;
    int sum = 0;
    for (auto it : arr)
    {
        sum += it;
    }
    int h = sum;
    int ans = 0;
    int mid = l + (h - l) / 2;
    while (l <= h)
    {
        if (canRead(arr, m, mid))
        {
            h = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
        mid = l + (h - l) / 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}