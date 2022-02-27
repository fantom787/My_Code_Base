#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    unordered_map<int, int> hm;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        hm[arr[i][0]]++;
    }
    int total = 2 * (n - 1);
    for (int i = 0; i < n; i++)
    {
        int hmMatch = n - 1 + hm[arr[i][1]];
        int awMatch = total - hmMatch;
        cout << hmMatch << " " << awMatch << endl;
    }

    return 0;
}