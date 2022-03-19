#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

bool chk(string date, string month, string year)
{
    int date1 = stof(date);
    int month1 = stof(month);
    int year1 = stof(year);

    if (year1 < 2013 || year1 > 2015)
    {
        return false;
    }
    if (month1 < 1 || month1 > 12)
    {
        return false;
    }
    map<int, int> dates;
    for (int i = 1; i < 13; i++)
    {
        if (i < 8)
        {
            if (i & 1)
            {
                dates[i] = 31;
            }
            else
            {
                dates[i] = 30;
            }
        }
        else
        {
            if (i & 1)
            {
                dates[i] = 30;
            }
            else
            {
                dates[i] = 31;
            }
        }
    }
    dates[2] = 28;
    if (dates[month1] < date1 || date1 < 1)
    {
        return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    map<string, int> ans;
    for (int i = 0; i < n - 9; i++)
    {
        bool flag = true;
        for (int j = i; j < i + 10; j++)
        {
            if (((j - i) == 2 || (j - i) == 5))
            {
                if (s[j] != '-')
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (s[j] == '-')
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            if (chk(s.substr(i, 2), s.substr(i + 3, 2), s.substr(i + 6, 4)))
            {
                ans[s.substr(i, 10)]++;
            }
        }
    }
    string ans_str;
    int max = -1;
    for (auto it : ans)
    {
        if (it.second > max)
        {
            max = it.second;
            ans_str = it.first;
        }
    }
    cout << ans_str << endl;
    return 0;
}