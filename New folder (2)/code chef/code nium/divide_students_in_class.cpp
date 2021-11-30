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

int stu12(map<int, int> ht)
{
    int total = 0;
    for (auto it : ht)
    {
        total += it.second;
    }
    if (total >= 12)
    {
        return 1;
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    map<int, int> ht;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        ht[temp]++;
    }
    if (ht.size() > 12)
    {
        cout << "no" << endl;
    }
    else if (ht.size() == 12)
    {
        cout << "yes" << endl;
    }
    else if (ht.size() < 12 && stu12(ht))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
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
You are given the heights of n students who want to attend a school. The school, being weird as usual, has a condition that all the students in a class should have the same height. Also, the school runs only 12 classes from class 1 to class 12.

Find out whether it is possible for you to divide all the n students into 12 classes. Note that in each class, there should be at least one student, and the heights of all the students should be equal. Multiple classes can have students with the same height also.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer n.
The second line contains n space-separated integers h1,h2,…,hn denoting the heights of the students.
Output
For each test case, print a single line containing "yes" or "no" (without quotes) depending on the situation.

Constraints
1≤T≤10
1≤n≤105
1≤hi≤105
Subtasks
For 40% of the score: 1≤n,hi≤100
Remaining 60%: No extra constraints.
Sample Input
3
3
1 2 3
12
1 2 3 4 5 6 7 8 9 10 11 12
14
1 1 1 1 1 1 1 1 1 1 1 1 1 1
Sample Output
no
yes
yes
Explanation
Example case 1: There are only three students. So there is no way that there can be at least one student in each class.

Example case 2: There are only twelve students. Each student can go into a separate class.

Example case 3: There are total fourteen students. One way of dividing them into classes will be class 1 to 10, one student each. While 11th and 12th class have two each.
*/
