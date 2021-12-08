//  [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int firstMissingPositive(vector<int> &nums)
{
    unordered_set<int> s;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
        /* code */
    }
    int i = 1;
    while (1)
    {
        if (s.find(i) == s.end())
        {
            return i;
        }
        i++;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vi vec1 = {7,8,9,11,12};
    cout << firstMissingPositive(vec1);
    return 0;
}

