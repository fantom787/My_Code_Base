/*
bahut simple hai dekho sbse pehle hmare sath mzak to nhi kr dia null deke to dekho ki null to nhi hai
fir kro search aur usme pta lagao ki wo kha hai
maan lo ki wo root node hi hai
fir kya kro ki uska predecessor se replace kr do
aur predecessor ko free kr do simple!!!!!

*/

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
void traversal(node *root)
{
    if (root != NULL)
    {
        traversal(root->left);
        cout << root->data << " ";
        traversal(root->right);
    }
}

node *previous(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *deletion(node *root, int value)
{
    node *pre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching
    if (value < root->data)
    {
        root->left = deletion(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletion(root->right, value);
    }
    else
    {
        pre = previous(root);
        root->data = pre->data;
        root->left = deletion(root->left, pre->data);
    }
    return root;
}

int main()
{
    node *p = new node(5);  //         5
    node *p1 = new node(2); //    2         7
    node *p2 = new node(7); // 1     4   6      8
    node *p3 = new node(1);
    node *p4 = new node(4);
    node *p5 = new node(6);
    node *p6 = new node(8);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    traversal(p);
    cout << endl;
    deletion(p, 1);
    traversal(p);

    return 0;
}