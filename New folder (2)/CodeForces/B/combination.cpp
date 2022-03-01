#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
//#define sort(x) sort(x.begin(), x.end());

void display(vector<pair<int, int>> vec)
{
    for (auto it : vec)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> cards(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cards[i] = {y, x};
    }
    int moves = 1;
    int score = 0;
    sort(cards.begin(), cards.end(), [](pair<int, int> a, pair<int, int> b)
         {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        else
        {
            return a.second>b.second;
        } });
    int idx = 0;
    while (moves-- && idx < n)
    {
        moves += cards[idx].first;
        score += cards[idx++].second;
    }
    cout << score << endl;
    return 0;
}