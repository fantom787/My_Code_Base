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

int height(node *root)
{
	if (root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return 1 + max(lh, rh);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	node *p = new node(5);
	node *p1 = new node(6);
	node *p2 = new node(7);
	node *p3 = new node(8);
	p->left = p1;
	p->right = p2;
	p2->right = p3;
	cout << height(p);

	return 0;
}