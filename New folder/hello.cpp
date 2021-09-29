#include <iostream>

using namespace std;
float sum(float a, float b)
{
    float c;
    c = a + b;
    cout << "the sum of " << a << "+ " << b << " is : " << c;
    return c;
}
int main()
{
    int a = 5;
    float b = 5.15;
    char c = 'b';
    cout << "hello world"
         << "\nthe value of a is " << a << "\nthe value of float b is " << b << "\nthe value of char c is " << c<<"\n";

    sum(a, b);
    return 0;
}