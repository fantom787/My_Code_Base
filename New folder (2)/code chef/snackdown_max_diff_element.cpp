#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

void solve()
{
    ll n, temp;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ans.push_back(make_pair(temp, i));
    }
    sort(ans.begin(), ans.end());
    int k = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].first > k)
        {
            ans[i].first = k;
            k++;
        }
        else
        {
            ans[i].first = k;
        }
    }
    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " ";
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
    while (n--)
    {
        solve();
    }

    return 0;
}
/*
Given an array B of length N, find an array A of length N where 0≤Ai≤109 such that array C where Ci=AimodBi, ∀i∈{1,2,...,N} has maximum number of distinct integers.

In case of multiple answers, print any.

Input Format
First-line will contain T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
First-line contains a single integer N.
Second-line contains N space-separated integers B1,B2,…,BN.
Output Format
For each test case, output in a single line N space-separated integers A1,A2,…,AN, the elements of the array A such that array C has the maximum number of distinct elements.

If the output array doesn't follow the constraints or the number of distinct elements in the array C is less than the optimal value, you will receive a wrong answer verdict.

Constraints
1≤T≤105
1≤N≤2⋅105
1≤Bi≤N
0≤Ai≤109
Sum of N over all tests is atmost 106.
Sample Input 1 
3
3
2 1 3
2
1 1
6
1 2 3 3 2 1
Sample Output 1 
3 1 2
2 3
0 1 2 3 4 5
Explanation
Test Case 1: Array C={3mod2,1mod1,2mod3}={1,0,2}. So the number of unique elements are 3.

Test Case 2: Array C={2mod1,3mod1}={0,0}. So the number of unique elements is 1.

Test Case 3: Array C ={0mod1,1mod2,2mod3,3mod3,4mod2,5mod1} ={0,1,2,0,0,0}. So the number of unique elements are 3.

In all the 3 cases, the number of unique elements can't be increased any further for any choice of the array A.
*/