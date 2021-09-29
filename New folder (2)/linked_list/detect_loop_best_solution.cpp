#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

void display(node *root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
	cout << endl;
}
/*
dekho simple hai 1 ko fast chalao 1 ko slow jb dono brabar ho jaynge to return 1 kr dena
*/

int loop(node *root)
{
	node *fast = root;
	node *slow = root;
	while (root != NULL)
	{
		if (fast == slow)
		{
			return 1;
		}
		slow = slow->next;
		fast = fast->next->next;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	node *root = new node(5);
	root->next = new node(6);
	root->next->next = new node(7);
	root->next->next->next = new node(11);
	root->next->next->next->next = new node(10);
	root->next->next->next->next->next = new node(9);
	root->next->next->next->next->next->next = root->next->next;
	cout << loop(root);

	return 0;
}