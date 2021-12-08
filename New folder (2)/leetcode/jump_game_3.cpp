#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

bool canReach(vector<int> &arr, int start)
{
    unordered_set<int> s;
    int n = arr.size();
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if (!arr[temp])
        {
            return true;
        }
        s.insert(temp);
        int left = temp - arr[temp];
        int right = temp + arr[temp];
        if (left >= 0 && (s.find(left) == s.end()))
        {
            q.push(left);
        }
        if (right < n && (s.find(right) == s.end()))
        {
            q.push(right);
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}