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
    if(n != NULL )
    {
        cout<< n->data<<" ";
        traversal(n->left);
        traversal(n->right);
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

    return 0;
}