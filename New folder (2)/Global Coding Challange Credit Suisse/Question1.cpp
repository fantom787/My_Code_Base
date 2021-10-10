
using namespace std;
#include <string>
#include <iostream>

int solution(int n){
    int ans=(n/3)*2;
    if(n%3)
        ans+=1;
    return ans;
}

/*  Do not edit below code */
int main() {
	int n;
	cin >> n;	
    int answer=solution(n);
	cout << answer << endl;	
}

