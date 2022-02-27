#include <bits/stdc++.h>
using namespace std;

class name
{
public:
        char s[1000];
};

void abriviation(char *s)
{
        int length = strlen(s);
        if (length<11)
        {
                cout<<s<<endl;
                return;
        }
        
        char starting = s[0];
        char ending = s[strlen(s) - 1];
        cout << starting << length-2 << ending << endl;
}

int main()
{
        int n, length;
        cin >> n;
        name s[n];
        for (int i = 0; i < n; i++)
        {
                scanf("%s",&s[i].s);
        }
        for (int i = 0; i < n; i++)
        {
                abriviation(s[i].s);
        }

        return 0;
}