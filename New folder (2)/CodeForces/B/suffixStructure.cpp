#include <bits/stdc++.h>
using namespace std;
#define endl "\n";
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> m1, m2;
    int n1 = s.length();
    int n2 = t.length();
    for (auto it : s)
    {
        m1[it]++;
    }
    for (auto it : t)
    {
        m2[it]++;
    }
    for (int i = 0; i < 26; i++)
    {
        m1[char('a' + i)] += 0;
    }
    bool f1 = false;
    for (auto it : m1)
    {
        if (it.second < m2[it.first])
        {
            cout << "need tree" << endl;
            return 0;
        }
        else if (it.second > m2[it.first])
        {
            f1 = true;
        }
    }
    int c = 0;
    bool f2 = false;
    for (int i = 0; i < n1; i++)
    {
        if (c == n2)
            break;
        else if (s[i] == t[c])
            c++;
    }
    // cout<<"c: "<<c<<"n2: "<<n2<<endl;
    if (c != n2)
        f2 = true;

    if (f1 && f2)
    {
        cout << "both" << endl;
    }
    else if (f1)
    {
        cout << "automaton" << endl;
    }
    else if (f2)
    {
        cout << "array" << endl;
    }
    return 0;
}