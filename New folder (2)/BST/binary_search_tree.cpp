#include <iostream>
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

void traversal(node *n)
{
    if (n != NULL)
    {
        traversal(n->left);
        cout << n->data << " ";
        traversal(n->right);
    }
}

int isbst(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isbst(root->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    node *p = new node(5);
    node *p1 = new node(4);
    node *p2 = new node(7);
    p->left = p1;
    p->right = p2;
    traversal(p);

    return 0;
}