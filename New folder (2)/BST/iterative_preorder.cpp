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

vector<int> preorder(node *root)
{
    vector<int> pre;
    stack<node *> s1;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        pre.push_back(root->data);
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
    }
    return pre;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}