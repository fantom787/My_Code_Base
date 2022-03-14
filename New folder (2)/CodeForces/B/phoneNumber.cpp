#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define sort(x) sort(x.begin(), x.end());
#define all(x) s.begin(), s.end();

int main()
{

    int n;
    cin >> n;
    map<int, string> name;
    map<int, int> taxi;
    map<int, int> piz;
    map<int, int> cg;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        string prs;
        cin >> prs;
        name[i] = prs;
        taxi[i] = 0;
        piz[i] = 0;
        cg[i] = 0;
        for (int j = 0; j < num; j++)
        {
            string s;
            cin >> s;
            char prev = s[0];
            bool f1 = true; // for taxi
            bool f2 = true; // for pizza
            for (int k = 1; k < 8; k++)
            {
                if (isdigit(s[k]) && s[k] != prev)
                {
                    f1 = false;
                    break;
                }
            }
            if (f1)
            {
                taxi[i]++;
                continue;
            }
            for (int k = 1; k < 8; k++)
            {
                if (isdigit(s[k]) && (s[k] >= prev))
                {
                    f2 = false;
                    break;
                }
                if (isdigit(s[k]))
                {
                    prev = s[k];
                }
            }
            if (f2)
            {
                piz[i]++;
                continue;
            }
            cg[i]++;
        }
    }
    int maxiT = INT_MIN;
    int maxiP = INT_MIN;
    int maxiC = INT_MIN;
    map<int, vector<string>> taxiP;
    map<int, vector<string>> pizP;
    map<int, vector<string>> cgP;
    for (auto it : taxi)
    {
        maxiT = max(it.second, maxiT);
        taxiP[it.second].push_back(name[it.first]);
    }
    for (auto it : piz)
    {
        maxiP = max(it.second, maxiP);
        pizP[it.second].push_back(name[it.first]);
    }

    for (auto it : cg)
    {
        maxiC = max(it.second, maxiC);
        cgP[it.second].push_back(name[it.first]);
    }

    string taxiAns = "If you want to call a taxi, you should call: ";
    for (auto it : taxiP[maxiT])
    {
        taxiAns += (it + ", ");
    }
    taxiAns.pop_back();
    taxiAns.pop_back();
    taxiAns += ".";
    string pizAns = "If you want to order a pizza, you should call: ";
    for (auto it : pizP[maxiP])
    {
        pizAns += (it + ", ");
    }
    pizAns.pop_back();
    pizAns.pop_back();
    pizAns += ".";
    string cgAns = "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (auto it : cgP[maxiC])
    {
        cgAns += (it + ", ");
    }
    cgAns.pop_back();
    cgAns.pop_back();
    cgAns += ".";
    cout << taxiAns << endl;
    cout << pizAns << endl;
    cout << cgAns << endl;
    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;


int main() {

    int n;
    cin>>n;
    map<int,string>name;
    map<int,int>taxi;
    map<int,int>piz;
    map<int,int>cg;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        string prs;
        cin>>prs;
        name[i]=prs;
        for(int j=0;j<num;j++)
        {
            string s;
            cin>>s;
            char prev = s[0];
            bool f1 = true;// for taxi
            bool f2 = true;// for pizza
            for(int k =1;k<8;k++)
            {
                if(isdigit(s[k])&&s[k]!=prev)
                {
                    f1 = false;
                    break;
                }
            }
            if(f1)
            {
                taxi[i]++;
                continue;
            }
            for(int k=1;k<8;k++)
            {
                if(isdigit(s[k])&&s[k]+1!=prev)
                {
                    f2 = false;
                    break;
                }
                else
                {
                    prev = s[k];
                }
            }
            if(f2)
            {
                piz[i]++;
                continue;
            }
            cg[i]++;

        }
    }
    int maxiT = INT_MIN;
    int maxiP = INT_MIN;
    int maxiC = INT_MIN;
    map<int,vector<string>>taxiP;
    map<int,vector<string>>pizP;
    map<int,vector<string>>cgP;
    for(auto it:taxi)
    {
        maxiT=max(it.second,maxiT);
        taxiP[it.second].push_back(name[it.first]);
    }
    for(auto it:piz)
    {
        maxiP=max(it.second,maxiP);
        pizP[it.second].push_back(name[it.first]);
    }

     for(auto it:cg)
    {
        maxiC=max(it.second,maxiC);
        cgP[it.second].push_back(name[it.first]);
    }

    cout<<"If you want to call a taxi, you should call: ";
    for(auto it:taxiP[maxiT])
    {
        cout<<it<<", ";
    }
    cout<<"."<<endl;

    cout<<"pizP ka size"<<pizP.size()<<endl;
     cout<<"If you want to order a pizza, you should call: ";
    for(auto it:pizP[maxiP])
    {
        cout<<it<<", ";
    }
    cout<<"."<<endl;

    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    for(auto it:cgP[maxiC])
    {
        cout<<it<<", ";
    }
    cout<<"."<<endl;

    return 0;
}

*/