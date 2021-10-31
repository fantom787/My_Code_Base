#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void display(vector<int> v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";
}

int floor(node *root, int key)
{
    int flor = INT_MIN;
    while (root)
    {
        if (root->data == key)
        {
            return key;
        }
        if (root->data < key)
        {
            flor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}