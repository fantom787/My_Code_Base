#include <iostream>
using namespace std;

void inpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}
void zpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void rhpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < 2 * a - (i + 1); j++)
        {
            if (j < a - (i + 1))
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
void nppattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}
void plpattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1 - j << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << j + 2 << " ";
        }
        cout << endl;
    }
}
void spattern(int a)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = a; i > 0; i--)
    {
        for (int j = 0; j < a - i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void zigzagpattern(int a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (((i + j+2) % 4 == 0) || ((i+1) == 2 && (j+1) % 4 == 0))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int a = 5;
    inpattern(a);
    zpattern(a);
    rhpattern(a);
    nppattern(a);
    plpattern(a);
    spattern(a);
    cout << endl
         << endl;
    zigzagpattern(9);

    return 0;
}