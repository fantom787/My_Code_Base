#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

string skip(string s)
{
    if (s.empty())
    {
        return "\0";
    }
    if (s.find("apple"))
    {
        return skip(s.substr(1));
    }
    else
    {
        return s[0] + skip(s.substr(1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "baccdah";
    cout<<skip(s);

    return 0;
}