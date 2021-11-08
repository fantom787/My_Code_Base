#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int largestAltitude(vector<int> &gain)
{
    int ans = 0;
    int temp = 0;
    for (int i = 0; i < gain.size(); i++)
    {
        ans = max(ans, temp);
        temp += gain[i];
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