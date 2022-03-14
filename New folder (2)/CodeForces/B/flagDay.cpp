#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> dancer(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        unordered_set<int> st;
        for (int i = 1; i < 4; i++)
        {
            st.insert(i);
        }
        if (dancer[x-1] != 0)
        {
            st.erase(dancer[x-1]);
        }
        else if (dancer[y-1] != 0)
        {
            st.erase(dancer[y-1]);
        }
        else if (dancer[z-1])
        {
            st.erase(dancer[z-1]);
        }
        if (!dancer[x-1])
        {
            dancer[x-1] = (*st.begin());
            st.erase(dancer[x-1]);
        }
        if (!dancer[y-1])
        {
            dancer[y-1] = (*st.begin());
            st.erase(dancer[y-1]);
        }
        if (!dancer[z-1])
        {
            dancer[z-1] = (*st.begin());
            st.erase(dancer[z-1]);
        }
    }
    for (auto it : dancer)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}