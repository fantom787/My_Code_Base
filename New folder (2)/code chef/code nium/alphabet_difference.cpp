// https://www.codechef.com/NIUM2101/problems/DIVCLASS
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void solve()
{
    // can be done using map
    string a;
    string b;
    set<char> aa;
    set<char> bb;
    set<char> cc;
    cin >> a >> b;
    for (int i = 0; i < a.end(); i++)
    {
        aa.insert(a[i]);
    }
    for (int i = 0; i < b.end(); i++)
    {
        bb.insert(b[i]);
    }

    cc = set_intersection(aa.begin(), aa.end(), bb.begin(), bb.end());
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
You are given two strings A and B containing small english alphabets ['a' - 'z']. You have to find the set of distinct characters that are present in string B but not in A. Print this set of characters sorted in increasing order in the form of a string. 

If there are no such characters that are present in B but not in A, then print -1.   

Note
You just need to print an alphabet once in the resultant string if its present in string B but not in string A.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
First line of each testcase contains string A.
Second line of each testcase contains string B.
Output
For each test case, output a single line containing answer. 

Constraints
1 ≤ T ≤ 20
1 ≤ Length of string A , B ≤ 100000 
Information to Score Partial Points
For 5% of the score, it is guaranteed that Length of strings are  ≤ 26 and all alphabets in string B are distinct.
For 30% of the score, it is guaranteed that Length of strings are  ≤ 500.
For rest 65% of the score, original constraints are applicable.
Example
Input:
2
codechef
certification
teacher
cheater

Output:
ainrt
-1
*/