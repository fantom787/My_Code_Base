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

void insert(node *root, int key)
{
    node *prev;
    node *new1;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            cout << "cannot insert " << key << "already exist" << endl;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    new1 = new node(key);
    if (key > prev->data)
    {
        prev->right = new1;
    }
    else
    {
        prev->left = new1;
    }
}
void traversal(node *n)
{
    if (n != NULL)
    {
        traversal(n->left);
        cout << n->data << " ";
        traversal(n->right);
    }
}

int main()
{
    node *p = new node(5);
    node *p1 = new node(4);
    node *p2 = new node(7);
    p->left = p1;
    p->right = p2;
    insert(p, 8);
    insert(p, 2);
    insert(p, 3);
    insert(p, 99);
    traversal(p);

    return 0;
}