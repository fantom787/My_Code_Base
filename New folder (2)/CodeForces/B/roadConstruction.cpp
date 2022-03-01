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
    set<int> st;
    for (int i = 1; i < n + 1; i++)
    {
        st.insert(i);
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (st.find(x) != st.end())
            st.erase(x);
        if (st.find(y) != st.end())
            st.erase(y);
    }
    cout << n - 1 << endl;
    int val = *st.begin();
    for (int i = 1; i < n + 1; i++)
    {
        if (i != val)
            cout << val << " " << i << endl;
    }

    return 0;
}