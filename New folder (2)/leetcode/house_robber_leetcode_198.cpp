#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//  recusive soln (not prefered ) time complexity = 2^n
//  2 1 5 7 8
/*
    dekho bahut simple hai 
    yaa to 1st ko lelo + me 3rd se age koi element  ko lelo mtlb recursive fn chala do
    yaa 1st ko mt lo aur 2nd wale se recusive fn chala do
*/
int max_chori_recursive(int *v, int n)
{
    // int arr[] = {1, 2, 2, 3};
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return v[n];
    }
    return max(max_chori_recursive(v, n - 1), max_chori_recursive(v, n - 2) + v[n]);
}

//  ab lagayenge dp ki aproach #best_aproach
// isme kya krna hai j ki 1st ko prev kr do nd ist and 2nd me se bda nikal lo current me store kr do
// fir kya kro ki loop chalao 2 se n tk
//  isme kya kro ki 1st aur 3rd ke sum aur current ke sum me se jo max hai uski value ko current me daal do
// isme hm kya kr rhe hai ki 1 array ko chote array me tod rhe hai
/*
aur 2 pointer maintain kr rhe hai 1 current jo jitna array solve hua hai uska answer hai aur 1 prev jo last answer tha 
agle element me jane pe hm last answr me usko add krke apne current se comare krnege ki bda hai ki nhi
agr hai toh jo apni current value ko update kr denge aur previous value ko hm apni last current value de denge
aur isi tarah pure loop me ghumenge
*/

int max_chori_dp(int *arr, int n)
{
    int pev = arr[0];
    int current = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int temp = current;
        current = max(pev + arr[i], current);
        pev = temp;
    }
    return current;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int arr[] = {1, 2, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    cout << max_chori_recursive(arr, size-1) << endl;
    cout << max_chori_dp(arr, size);

    return 0;
}