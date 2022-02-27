#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    vector<string> ans;
    unordered_map<string, string> um;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        um[temp1] = temp2;
    }
    for (int i = 0; i < n; i++)
    {
        string temp1;
        cin >> temp1;
        int s1 = temp1.size();
        int s2 = um[temp1].size();
        if (s2 < s1)
        {
            ans.push_back(um[temp1]);
        }
        else
        {
            ans.push_back(temp1);
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}