#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int searchiter(node *root, int element)
{
    while (root != NULL)
    {
        if (root->data == element)
        {
            return 1;
        }
        if (root->data > element)
        {
            root = root->left;
        }
        if (root->data < element)
        {
            root = root->right;
        }
    }

    return 0;
}
void traversal(node *n)
{
    if (n != NULL)
    {
        traversal(n->left);
        traversal(n->right);
        cout << n->data << " ";
    }
}

int main()
{
    node *p = new node(5);
    node *p1 = new node(6);
    node *p2 = new node(7);
    p->left = p1;
    p->right = p2;
    traversal(p);
    if (searchiter(p, 5))
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element Not Found" << endl;
    }

    return 0;
}