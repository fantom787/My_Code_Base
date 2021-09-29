#include <bits/stdc++.h>
using namespace std;

int main()
{
	 int n = 456789;
	 int reverse = 0;
	 while (n>0)
	 {
		 int lastdigit = n%10;
		 reverse = reverse*10 +lastdigit;
		 n/=10;
	 }
	 cout<<reverse;	
	  
	 return 0;
}