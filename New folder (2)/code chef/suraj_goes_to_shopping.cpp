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
    int n;
    cin >> n;
    vector<int> vec1;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec1.push_back(temp);
    }
    sort(all(vec1));
    reverse(all(vec1));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 4 < 2)
        {
            sum += vec1[i];
        }
    }
    cout << sum << endl;
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
Read problems statements in Mandarin Chinese and Russian as well.
Problem description
It is winter super sale and all the shops have various offers. Suraj selected N items to buy and he is standing in the billing queue. It was then he noticed the offer "Buy two, get two". That means for every two items you buy, they give you two items for free. However, items can be of varying price, they always charge for 2 most costly items and give other 2 as free. For example, if the items cost 1, 1, 2, 2, then you have to pay 4 and take all 4 items.

Suraj is busy reordering his items to reduce the total price he has to pay. He can separate the items and get them on different bills if needed. Can you tell me what is the least price Suraj has to pay to buy all the N items?

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. First line of each test case has single integer N. Second line of each test case has N space separated integers, which are the costs of items Suraj want to buy.

Output
For each test case, output a single line containing the required answer.

Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1000
1 ≤ Cost of items ≤ 1000
Sample Input 1 
3
4
1 1 2 2
2
10 200
7
1 1 10 2 2 2 1
Sample Output 1 
4
210
14
Explanation
Example case 1
Suraj pays for 2 costly items and gets other 2 for free.

Example case 2
Suraj has to pay for both the items, he wont get anything for free.

Example case 3
Suraj separates the items into 2 bills. In one bill he pays 12. And in another bill he pays 2.
*/