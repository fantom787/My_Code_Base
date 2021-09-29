/*
                    BFS  -> bredth first search
        dekho bahut simple hai
        jo hmne root mila hai use queue me daal do
        fir check kro ki uska left right nhi hai na
        agr hai to us root ko pop krke vector me daal do
        fir age left right ke liye chalao

*/
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
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> bfs(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<node *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        int size = q1.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *temp = q1.front();
            q1.pop();
            if (temp->left != NULL)
            {
                q1.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q1.push(temp->right);
            }
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    node *root = new node(1);
    node*

    return 0;
}