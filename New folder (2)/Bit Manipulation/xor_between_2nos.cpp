/* 
 2 nos ke beech xor krna hai
dekho bde wale ke xor ko chote wale se xor se xor kra do
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int find_xor(int n)
{
    int ans = n % 4;
    if (ans == 0)
    {
        return n;
    }
    else if (ans == 1)
    {
        return 1;
    }
    else if (ans == 2)
    {
        return n + 1;
    }
    return 0;
}

int xor_between_2_nos(int a , int b)
{
    int ans = find_xor(a-1)^find_xor(b);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<xor_between_2_nos(3,9);
      
     return 0;
}