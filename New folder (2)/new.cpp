#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {5, 7, 7, 8, 8, 10};
    auto it = lower_bound(vec1.begin(),vec1.end(),7);
    int low = it - vec1.begin();
    cout<<low;

    return 0;
}