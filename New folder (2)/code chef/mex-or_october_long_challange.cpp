#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
dekho bahut simple hai 
dekho simple hai bhai wo wala answer do jiske tk ka or x se chota ya barabar ho
1st edge case hai ki agr x =0 to 1 return kr do as {0} ka mex to 1 hoga na
2nd edge case hai ki agr x =1 to 2 return kr do as {0,1} ka mex 2 hoga na
3rd edge case hai ki agr x =2 to 2 return kr do as {0,1} ka mex 2 hoga na 
        ab swal ye hai ki hmne 2 include kyu nhi kra
        seedha answer hai agr include kr dete to or unka 3 ho jata and wo hamare x ke or se jyada ho jata so ans galat ho jata

**** ye ho gye edge cases ****
ab baat krte hai answer kaise nikalna hai

to dekho  agr koi no diya hai maan lo 9 to iska or 0 se 9 tk hoga apna 15(2^4-1) solve krke dekh lena
to koi no given hai hme maan lo wo 2^n hai toh usi ko print kr do kyuki usse pehle wale no ka or 2^n-1 hoga and uska or  chota hai x  se


agr koi no 2^n-1 mil jata hai
to 2^n print kr do bcz usse pehle ke or ka x ke barabar hoga

*/
void solve()
{
    ll x;
    cin >> x;
    ll ans = 1;
    if (x == 0)
    {
        cout << 1 << endl;
        return;
    }
    else if (x == 1)
    {
        cout << 2 << endl;
        return;
    }
    else if (x == 2)
    {
        cout << 2 << endl;
        return;
    }
    else
    {
        while (ans * 2 <= x)
        {
            ans *= 2;
        }
        if (ans == x)
        {
            cout << x << endl;
        }
        else if (x == (2 * ans) - 1)
        {
            cout << x + 1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
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
The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

The MEX of [2,2,1] is 0, because 0 does not belong to the array.
The MEX of [3,1,0,1] is 2, because 0 and 1 belong to the array, but 2 does not.
The MEX of [0,3,1,2] is 4 because 0,1,2 and 3 belong to the array, but 4 does not.
Find the maximum possible MEX of an array of non-negative integers such that the bitwise OR of the elements in the array does not exceed X.

Input Format
The first line contains T denoting the number of test cases. Then the test cases follow.
Each test case contains a single integer X on a single line.
Output Format
For each test case, output on a single line the maximum possible MEX of the array satisfying the given property.

Constraints
1≤T≤105
0≤X≤109
Subtasks
Subtask 1 (100 points): Original constraints

Sample Input 1 
4
0
1
2
5
Sample Output 1 
1
2
2
4
Explanation
Test case 1: The array could be [0].

Test case 2: The array could be [0,1]. Here the bitwise OR of 0 and 1 is 1 and the MEX of the array is 2 as both 0 and 1 belongs to the array.

Test case 4: The array could be [1,0,3,2]. Here the bitwise OR of all integers in the array is 3 and the MEX of the array is 4.


*/
