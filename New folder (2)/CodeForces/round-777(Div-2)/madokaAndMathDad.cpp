#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535;
#define endl "\n";
#define ll long long int
#define all(s) s.begin(), s.end()

void solve()
{
    int n;
    cin >> n;
    if (n % 3 == 0)
    {
        n /= 3;
        for (int i = 0; i < n; i++)
        {
            cout << 21;
        }
        cout << endl;
    }
    else if (n % 3 == 1)
    {
        n /= 3;
        for (int i = 0; i < n; i++)
        {
            cout << 12;
        }
        cout << 1 << endl;
    }
    else
    {
        n /= 3;
        for (int i = 0; i < n; i++)
        {
            cout << 21;
        }
        cout << 2 << endl
    }
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

In reply to Deya Abu-Elwan]
int n;
        cin>>n;
        if(n%3==0){n=n/3;

            for(int i=0;i<n;i++){
                cout<<"21";
            }
            cout<<endl;
        }
        else if(n%3==1){n=n/3;

            for(int i=0;i<n;i++){
                cout<<"12";
            }
            cout<<1<<endl;
        }
        else{n=n/3;
            for(int i=0;i<n;i++){
                cout<<"21";
            }
            cout<<2<<endl;
        }

*/

/*

danish, [11-03-2022 20:23]
#include<bits/stdc++.h>
#include<string>
#include <iostream>
#include<vector>
#include<algorithm>
#define ll              long long
#define ull             unsigned long long
#define pb              push_back
using namespace std;


int main(){

     int t;
     cin>>t;

     while(t--){
         ll n;
         cin>>n;

         if(n==2){
             cout<<2<<endl;
         }
         else if(n==1){
             cout<<1<<endl;
         }
         else{

             if(n%2==0){
                 ll a=0;
                 while(a!=n){
                     cout<<1;
                  a=a+1;
                  if(a!=n){
                  cout<<2;
                  a=a+2;
                 }
                 }
                 cout<<endl;
             }
             else{
                 ll a=0;
                 while(a!=n){
                     cout<<2;
                     a=a+2;
                     if(a!=n){
                         cout<<1;
                         a=a+1;
                     }
                 }
                 cout<<endl;
             }
         }
     }


    return 0;
}

*/