#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << "Yes" << endl;
        cout << 0 << endl;
        return;
    }
    if (k % 2 == 0)
    {
        cout << "No" << endl;
        return;
    }
    ll sz = 0;
    for (ll i = 31; i >= 0; i--)
    {
        if (((1 << i) & k) != 0)
        {
            sz = i + 1;
            break;
        }
    }
    k = (k + (1 << sz) - 1) / 2;
    cout << "Yes" << endl;
    cout << sz << endl;
    int ans = 1;
    vector<int> a;
    for (int i = sz - 2; i >= 0; i--)
    {
        if (((1 << i) & k) != 0)
        {
            a.push_back(ans);
            ans += (1 << i);
        }
        else
        {
            ans -= (1 << i);
            a.push_back(ans);
        }
    }
    for (int i = sz - 2; i >= 0; i--)
        cout << a[i] << endl;
    cout << ans << endl;
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
Chef has a binary string S of length N, where the first K characters of S are '1', while the rest are '0'. He wants to make all the characters equal to '0'. You are allowed to perform the following operation on the string S as long as 2i−1≤N:

In the ith operation, you can select any contiguous range of 2i−1 indices of S and flip their values.
He can use the above operation any number of times. If there is no sequence of operations that can convert the string to all '0's, print NO.

Otherwise, print YES in the first line and then describe the operations. Print the starting indices of the contiguous range to be flipped in each operation. See Output Format for further details.

Input Format
First line of the input will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two integers N,K.
Output Format
For each test case, do the following:

If there is no sequence of operations to convert each character of S to '0', print NO.
Otherwise, print YES in the first line. (You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer)
In the second line print M, the number of operations you want to perform.
Then print M lines describing the operations. In the ith line, print the starting index L of the range [L,L+2i−1−1] flipped in the ith operation.
The value of L+2i−1−1 should not exceed N in any operation.
Constraints
1≤T≤5000
1≤N≤109
0≤K≤N
Sample Input 1 
3
5 0
3 3
2 2
Sample Output 1 
YES
0
YES
2
3
1
NO
Explanation
Test case 1: Since K=0, all the characters of string S are already '0'. So, there is no need to perform any operation.

Test case 2: We have N=3 and K=3. So S=111.

In first operation, we can choose index 3 (21−1=1 indices) and flip it, giving S=110.
In the second operation, we can choose indices 1,2 (22−1=2 indices) and flip them, giving S=000.
Therefore, we can make each character of S to '0' by flipping index 3 in first operation and indices 1 and 2 in the second operation.
*/