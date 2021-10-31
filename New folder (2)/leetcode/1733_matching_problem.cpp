// https://leetcode.com/problems/count-items-matching-a-rule/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int n = 0;
    if (ruleKey == "type")
    {
        n = 1;
    }
    else if (ruleKey == "color")
    {
        n = 2;
    }
    else if (ruleKey == "name")
    {
        n = 3;
    }

    int count = 0;
    for (int i = 0; i < items.size(); i++)
    {
        switch (n)
        {
        case 1:
            if (items[i][0] == ruleValue)
                count++;
            break;F
        case 2:
            if (items[i][1] == ruleValue)
                count++;
            break;
        case 3:
            if (items[i][2] == ruleValue)
                count++;
            break;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}