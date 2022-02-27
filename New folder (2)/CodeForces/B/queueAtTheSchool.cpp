#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++)
    {
        string temp = s;
        for (int j = 0; j < n; j++)
        {
            if (j + 1 < n && s[j] == 'B' && s[j + 1] == 'G')
            {
                swap(temp[j], temp[j + 1]);
            }
        }
        s = temp;
    }
    cout << s << endl;
    return 0;
}