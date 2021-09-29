/*
    bahut easy hai 
    dekho sabse pehle 
    kya kro ki last se shuru kro aur dekho ki agr koi element stack me hai ki nhi 
    agr hai to dekho ki usse chota hai to use pop kr do jb tk usse bda element na mil jaye 
    agr na mile to use -1 set kr do fir 
    agr mil gya to use uska nge declare kr do
    aur fir last me use push kr do stack me 
    isse kya hoga ki upar se neeche tk hamara stack 
    acending order me hoga
    hai na simple!!!
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int *nge(int *arr, int size)
{
    int *ngearr = new int[size];
    stack<int> s1;
    for (int i = 2 * size-1; i >= 0; i--)
    {
        while (!s1.empty() && s1.top() <= arr[i%size])
        {
            s1.pop();
        }
        if (s1.empty() == false)
        {
            ngearr[i % size] = s1.top();
        }
        else
        {
            ngearr[i % size] = -1;
        }
        s1.push(arr[i % size]);
    }
    return ngearr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[] = {1,3,4,2,1};
    int size = sizeof(arr)/sizeof(int);
    printarray(arr,size);
    int *arr1 = nge(arr,size);
    printarray(arr1,size);


    return 0;
}