#include <bits/stdc++.h>
using namespace std;
 
int Iseven(int a)
{
        if (a % 2 == 0)
        {
                return 1;
        }
        return 0;
}
 
int main()
{
        int n;
        cin >> n;
        if (Iseven(n) && n != 2)
        {
                cout << "YES";
        }
        else
        {
                cout << "NO";
        }
 
        return 0;
}