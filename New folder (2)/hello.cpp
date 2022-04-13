#include<bits/stdc++.h>
using namespace std;

bool isp[90000001];
vector<int>prime;

void seev()
{
    int maxN = 90000000;
    isp[0]=isp[1]=true;
    for(int i=2;i*i<=maxN;i++)
    {
        if(!isp[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
                isp[j]=true;
            }
        }
    }
    for(int i=2;i<=maxN;i++)
    {
        if(!isp[i])
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    seev();
    int t = 1;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        k--;
        cout<<prime[k]<<endl;
        
    }
    return 0;
}