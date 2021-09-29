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

int search(node *root, int element)
{
    if (root != NULL)
    {
        if (root->data == element)
        {
            return 1;
        }

        if (root->data < element)
        {
            search(root->right, element);
        }
        else
        {
            search(root->left, element);
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
    if (search(p, 5))
    {
        cout << endl
             << "Element Found" << endl;
    }
    else
    {
        cout << endl
             << "Element Not Found" << endl;
    }

    return 0;
}