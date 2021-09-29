#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int jonary_xd(int num, int n)
{
    ll length = log(num) / log(n) + 1;
    ll sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += num % n;
        num = num / n;
    }
    return sum;
}

int main()
{
    int temp, n;
    scanf("%d", &n);
    vector<ll> v1[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &temp);
            v1[i].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll min_log = INT_MAX, sum = INT_MAX;
        ll num, max, min;
        num = v1[i][0];
        min = v1[i][1];
        max = v1[i][2];
        for (int j = min; j < max; j++)
        {
            if (jonary_xd(num, j) < sum)
            {
                sum = jonary_xd(num, j);
                min_log = j;
            }
        }
        printf("%d\n", min_log);
    }

    return 0;
}
/*
Ques --->

Let f(n,B) be the sum of digits of the integer n when written in base B.

More formally, if n=∑i=0∞aiBi where ai is an integer in the range [0,B−1], then f(n,B)=∑i=0∞ai.

Given Q queries, each consisting of three integers n,l and r. Find the value of B corresponding to which f(n,B) is minimum for all l≤B≤r. If there are multiple such values, you can print any of them.

Input Format
The first line contains in single integer Q, the number of queries
Each of the next Q lines contain three space separated integers n,l and r respectively.
Output Format
For each query (n l r), print the value of base B which lies within [l,r] such that f(n,B) is minimum.
Constraints
1≤Q≤103
2≤n≤109
2≤l≤r≤109
Subtasks
Subtask #1 (50 points): original constraints

This problem is worth a total of 50 points and is meant to be complementary to the problem "MNDIGSM2" (also worth 50 points) which is very similar to this problem, but has slightly different constraints.

Sample Input 1 
3
216 2 7
256 2 4
31 3 5
Sample Output 1 
6
2
5
Explanation
To compute f(n,B), first write the integer n in the form a0+a1B+a2B2+… such that 0≤ai<B and ai is an integer. It can be shown that such a representation is unique. The sum of the digits is then ∑i=0∞ai (to be computed in base 10).

For example to compute f(216,2), observe that 216=27+26+24+23, and so the sum of digits is 1+1+1+1=4. Similarly, to compute f(216,100), write 216 as 2∗100+16 and so the sum of digits is 2+16=18.

Test case 1: We have f(216,2)=f(216,3)=4, f(216,4)=6, f(216,5)=8, f(216,6)=1 and finally f(216,7)=12. Clearly the minimum is obtained when B=6.

Test case 2: Note that f(256,2)=f(256,4) = 1, therefore both the answers 2 and 4 will be considered correct.

Test case 3: f(31,3)=f(31,5)=3 and f(31,4)=7, therefore both the answers 3 and 5 will be considered correct.
*/