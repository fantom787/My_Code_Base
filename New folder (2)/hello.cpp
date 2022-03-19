#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()
#define pb push_back
#define INF 1e9 + 7

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<int,set<int>> s;
    s[5].insert(5);
    auto x = s[5].find(1);
    cout << (x != s[6].end()) << endl;
    return 0;
}