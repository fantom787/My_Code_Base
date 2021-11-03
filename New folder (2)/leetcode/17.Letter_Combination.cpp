#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

void display(vector<string> vec1)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1[i] << " ";
    }
    cout << endl;
}

string charat(char c)
{
    string up;
    if (c == '1')
    {
        up = "";
        return up;
    }
    else if (c == '2')
    {
        up = "abc";
        return up;
    }
    else if (c == '3')
    {
        up = "def";
        return up;
    }
    else if (c == '4')
    {
        up = "ghi";
        return up;
    }
    else if (c == '5')
    {
        up = "jkl";
        return up;
    }
    else if (c == '6')
    {
        up = "mno";
        return up;
    }
    else if (c == '7')
    {
        up = "pqrs";
        return up;
    }
    else if (c == '8')
    {
        up = "tuv";
        return up;
    }
    else if (c == '9')
    {
        up = "wxyz";
        return up;
    }
    return up;
}

vector<string> phone_pad(string up, string p = "")
{
    vector<string> ans;
    if (up.empty())
    {
        vector<string> temp;
        if (p.empty())
        {
            return temp;
        }
        temp.push_back(p);
        return temp;
    }
    string up_c = charat(up[0]);
    for (int i = 0; i < up_c.size(); i++)
    {
        vector<string> sp = phone_pad(up.substr(1), p + up_c[i]);
        ans.insert(ans.end(), sp.begin(), sp.end());
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    display(phone_pad("23"));

    return 0;
}