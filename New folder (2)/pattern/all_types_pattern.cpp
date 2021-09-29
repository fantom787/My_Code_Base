#include <iostream>
using namespace std;

void dpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void upattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void lpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - (i + 1); j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void npattern(int a)
{
    int n = 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << n;
        }
        cout << endl;
        n++;
    }
}
void mpattern(int a)
{
    int n = 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << n << " ";
            n++;
        }
        cout << endl;
    }
}
void bpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 2 * a; j++)
        {
            if (j > i && j < 2 * (a)-i - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    for (int i = a; i >= 0; i--)
    {
        for (int j = 0; j < 2 * a; j++)
        {
            if (j > i && j < 2 * (a)-i - 1)
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

int main()
{
    int a = 5;
    dpattern(a);
    upattern(a);
    lpattern(a);
    npattern(a);
    mpattern(a);
    bpattern(a);

    return 0;
}