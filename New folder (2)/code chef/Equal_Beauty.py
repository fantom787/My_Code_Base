# cook your dish here
import math
from heapq import heappush, heappop, heapify
import random
import string
from collections import deque
from bisect import bisect, bisect_left, bisect_right, insort
import sys
input = sys.stdin.readline
def S(): return input().rstrip()


def I(): return int(S())
def M(): return map(int, S().split())
def L(): return list(M())


H = 1000000000+7
for _ in range(I()):
    n = I()
    l = L()
    l.sort()
    m = math.inf
    for i in range(2, n-1):
        d1 = l[i]-l[0]
        t = l[-1]-d1
        p = bisect_left(l, t, 1, i-1)
        if p == 1:
            m = min(m, abs(l[-1]-l[p]-d1))
            continue
        if p == i:
            m = min(m, abs(l[-1]-l[p-1]-d1))
            continue
        m = min(m, abs(l[-1]-l[p]-d1), abs(l[-1]-l[p-1]-d1))
    for i in range(1, n-2):
        m = min(m, abs(l[i]-l[0]-l[-1]+l[i+1]))
    x = [(l[0], 1)]
    for i in range(1, n):
        x.append((x[i-1][0]+l[i], x[i-1][1]+1))
    s = sum(l)
    for i in range(n):
        if n % 2 == 0:
            p = n//2
            if i >= n//2:
                p -= 1
                k = l[p]*x[p][1]-x[p][0]+(s-x[p][0]-l[i])-(n-1-x[p][1])*l[p]
            else:
                k = l[p]*(x[p][1]-1)-(x[p][0]-l[i]) + \
                    (s-x[p][0])-(n-x[p][1])*l[p]
        else:
            if i < n//2:
                p1 = n//2
                p2 = n//2 + 1
                k1 = l[p1]*(x[p1][1]-1)-(x[p1][0]-l[i]) + \
                    (s-x[p1][0])-(n-x[p1][1])*l[p1]
                k2 = l[p2]*(x[p2][1]-1)-(x[p2][0]-l[i]) + \
                    (s-x[p2][0])-(n-x[p2][1])*l[p2]
                k = min(k1, k2)
            elif i == n//2:
                p1 = n//2 - 1
                p2 = n//2 + 1
                k1 = l[p2]*(x[p2][1]-1)-(x[p2][0]-l[i]) + \
                    (s-x[p2][0])-(n-x[p2][1])*l[p2]
                k2 = l[p1]*x[p1][1]-x[p1][0] + \
                    (s-x[p1][0]-l[i])-(n-1-x[p1][1])*l[p1]
                k = min(k1, k2)
            else:
                p1 = n//2
                p2 = n//2 - 1
                k1 = l[p1]*x[p1][1]-x[p1][0] + \
                    (s-x[p1][0]-l[i])-(n-1-x[p1][1])*l[p1]
                k2 = l[p2]*x[p2][1]-x[p2][0] + \
                    (s-x[p2][0]-l[i])-(n-1-x[p2][1])*l[p2]
                k = min(k1, k2)
        m = min(k, m)
    print(m)
'''
The beauty of an (non-empty) array of integers is defined as the difference between its largest and smallest element.

For example, the beauty of the array [2,3,4,4,6] is 6−2=4.

An array A is said to be good if it is possible to partition the elements of A into two non-empty arrays B1 and B2 such that

B1 and B2 have the same beauty.
Each element of array A should be in exactly one array: either in B1 or in B2.
For example, the array [6,2,4,4,4] is good because its elements can be partitioned into two arrays B1=[6,4,4] and B2=[2,4], where both B1 and B2 have the same beauty (6−4=4−2=2).

You are given an array A of length N. In one move you can:

Select an index i (1≤i≤N) and either increase Ai by 1 or decrease Ai by 1.
Find the minimum number of moves required to make the array A good.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follow.
Each testcase contains two lines.
The first line contains N, the length of the array.
The second line contains N space-separated integers A1,A2,...,AN representing the initial array.
Output Format
For each testcase, output in a single line, the minimum number of moves required to make the given array good.

Constraints
1≤T≤105
2≤N≤105
−109≤Ai≤109
Sum of N does not exceeds 5⋅105 over all testcases
Sample Input 1 
2
3
4 2 6
4
-2 4 -2 4
Sample Output 1 
2
0
Explanation
Test Case 1: We can increase the first element(A1) by 2 in two moves. Now, the array A becomes [6,2,6], and is good, since it can be partitioned into two arrays, ([2],[6,6]), each with beauty 0.

Test Case 2: The given array ([−2,4,−2,4]) is good since it can be partitioned into two arrays ([−2,−2],[4,4]), each with beauty 0. Alternatively, it is also possible to partition it into ([−2,4],[−2,4]), each with beauty 6.
'''