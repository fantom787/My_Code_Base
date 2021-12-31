#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int find_Sqrt(int n)
{
    int l = 0;
    int h = n;
    long long int mid = l + (h - l) / 2;
    int ans = 0;
    while (l <= h)
    {
        long long int sqrt = mid * mid;
        if (sqrt > n)
        {
            h = mid - 1;
        }
        else if (sqrt < n)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            return mid;
        }
        mid = l + (h - l) / 2;
    }

    return ans;
}

double precicse_Sqrt(int n, int precision)
{
    double sqrt = find_Sqrt(n);
    double precise = 1;
    for (int i = 0; i < precision; i++)
    {
        precise /= 10;
        for (double j = sqrt; j * j <= n; j += precise)
        {
            sqrt = j;
        }
    }
    return sqrt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << precicse_Sqrt(2,10);
    return 0;
}