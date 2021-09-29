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
vector<int> inorder(node *root)
{
	node *ptr = root;
	vector<int> inoder;
	stack<node *> s1;
	while (1)
	{
		if (ptr != NULL)
		{
			s1.push(ptr);
			ptr = ptr->left;
		}
		else
		{
			if (s1.empty() == true)
			{
				break;
			}
			else
			{
				ptr = s1.top();
				s1.pop();
				inoder.push_back(ptr->data);
				ptr = ptr->right;
			}
		}
	}
	return inoder;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	node *root = new node(5);
	root->left = new node(4);
	root->right = new node(6);
	root->left->left = new node(3);
	root->right->right = new node(7);
	display(inorder(root));

	return 0;
}