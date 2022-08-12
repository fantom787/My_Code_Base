#include <bits/stdc++.h>
#define int long long
using namespace std;
void f(int n)
{
    int nn = n;
    set<int> st;
    for (int i = 2; i * i <= n; i++)
    {
        if (nn % i == 0)
        {
            int y = 1;
            while (nn % i == 0)
            {
                y *= i;
                nn /= i;
            }
            st.insert(y);
        }
    }
    if (nn > 1)
    {
        st.insert(nn);
    }
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
}
int32_t main()
{
    int n = 448630;
    f(n);
    f(447051);
    f(200560490130);
    return 0;
}