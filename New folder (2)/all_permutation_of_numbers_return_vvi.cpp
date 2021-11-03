#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vvi vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec1[i].size(); j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vvi all_permutation(vi arr)
{
    vi asd;
    vvi outer = {asd};
    for (int i = 0; i < arr.size(); i++)
    {
        int n = outer.size();
        for (int j = 0; j < n; j++)
        {
            vi internal = outer[j];
            internal.push_back(arr[i]);
            outer.push_back(internal);
        }
    }
    return outer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi arr = {1, 2, 3};
    vi inner;
    vvi outer = {inner};
    display(all_permutation(arr));

    return 0;
}