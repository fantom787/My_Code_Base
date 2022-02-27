#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string a, b;
    if (n & 1)
    {
        a = s.substr(0, n / 2);
        b = s.substr((n / 2) + 1, n / 2);
    }
    else
    {
        a = s.substr(0, n / 2);
        b = s.substr(n / 2, n / 2);
    }
    unordered_map<char, int> mp;
    for (auto it : a)
    {
        mp[it]++;
    }
    for (auto it : b)
    {
        mp[it]--;
    }
    for (auto it : mp)
    {
        if (it.second!=0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    /*
    for (auto it : a)
    {
        charArr[it - 'a']++;
    }
    for (auto it : b)
    {
        charArr[it - 'a']--;
    }
    for (auto it : charArr)
    {
        if (it)
        {
            cout << "NO" << endl;
            return;
        }
    }
    */
    cout << "YES" << endl;
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

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int c=s.length();

        int m,f,flag=0;
        if(c%2==0)
        {
            m=c/2;
            f=m;
        }
        else
        {
            m=c/2;
            f=m+1;
        }

        for(int j=0;j<m;j++)
        {
            char ch=s[j];
            int c1=1;
            for(int k=j+1;k<m;k++)
            {

                if(s[k]==ch)
                {
                    c1=c1+1;
                }
            }

            int c2=0;

            for(int l=f;s[l]!='\0';l++)
            {

                if(s[l]==ch)
                {
                    c2=c2+1;
                }
            }

            if(c1!=c2)
            {
                flag=1;
                break;
            }
            while(s[j+1]==ch && j<m)
            {
                j=j+1;
            }
        }
        if(flag==1)
        cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    // your code goes here
    return 0;
}


*/
