#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

string coma(string in)
{
    reverse(all(in));
    string ans;
    int cm = 0;
    for (auto it : in)
    {
        if (cm == 3)
        {
            ans += ",";
            cm = 0;
        }
        ans += it;
        cm++;
    }
    reverse(all(ans));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    cin >> input;
    string ans;
    // negative handled
    bool neg = false;
    bool decimal = false;
    if (input[0] == '-')
    {
        neg = true;
        ans += "($";
    }
    else
    {
        ans += "$";
    }
    int decIdx = input.find('.');
    int n = input.size();
    if (decIdx == string::npos || decIdx == n - 1)
    {
        if (neg)
        {
            ans += coma(input.substr(1));
            ans += ".00)";
        }
        else
        {
            ans += coma(input);
            ans += ".00";
        }
        cout << ans << endl;
        return 0;
    }
    string number;
    string deciNum;
    deciNum += input[decIdx + 1];
    if (decIdx + 1 != n - 1)
    {
        deciNum += input[decIdx + 2];
    }
    for (int i = 0; i < decIdx; i++)
    {
        number += input[i];
    }
    if (neg)
    {
        number = number.substr(1);
    }
    number = coma(number);
    ans += number;
    ans += ".";
    if (deciNum.size() == 1)
    {
        ans += deciNum;
        ans += "0";
    }
    else
    {
        ans += deciNum;
    }
    if (neg)
    {
        ans += ")";
    }
    cout << ans << endl;
    return 0;
}