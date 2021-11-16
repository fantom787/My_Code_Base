https://www.codechef.com/SPRE2021/problems/MAXWAGE
#include <bits/stdc++.h>
#define lli long long int 
using namespace std;

int main() {
    
    int t ;
    cin >> t ;
    while(t--)
    {
        
        int week ;
        cin >> week ;
        
        lli a , b , c ;
        cin >> a >> b >> c ;
        
        string s ;
        cin >> s ;
        
        int i = 0 ;
        
        vector<lli> avec ;
        vector<lli> bvec ;
        vector<lli> cvec ;
        
        avec.clear() ;
        bvec.clear() ;
        cvec.clear() ;
        
        while(i<s.length())
        {
            lli aa = 0 ;
            lli bb = 0 ;
            lli cc = 0 ;
            for(int j=i ; j<i+5 ; j++)
            {
                if(s[j]=='A') aa++ ; 
                else if(s[j]=='B') bb++ ;
                else cc++ ;
            }
            
            aa = aa*a ;
            bb = bb * b ;
            cc = cc * c;
            
            avec.push_back(aa) ;
            bvec.push_back(bb) ;
            cvec.push_back(cc) ;
            
            i+=5;
            
        }
        // from here starts dp
        lli red = avec[0] ;
        lli blue = bvec[0] ;
        lli green = cvec[0] ;

        for(int i=1 ; i<week ; i++)
        {
            lli nred = avec[i] + max(blue, green);
            lli nblue = bvec[i]+ max(red, green);
            lli ngreen = cvec[i] + max(red, blue);

            red = nred;
            blue = nblue;
            green = ngreen;
            
        }
        
        cout << max(red, max(blue,green)) << endl ;
        
       
        
    }
	// your code goes here
	return 0;
}
