#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int totalPairs(int n, vector<int>& arr) {
    // Complete the total pairs function
    
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i+1<n && arr[i+1]>arr[i])
            continue;
        
        int p=arr[i+1];
        for(int j=i+2;j<n;j++)
        {
            if(max(p,arr[j]) == arr[j])
            {
                ans++;
                p=arr[j];
            }
        }
    }
    
    return ans+(n-1);
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
