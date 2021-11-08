#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
/*
    ***** Explnation  ****
    left left insertion  ka case
        isme hamara newly inseted node root node ke left ke left me insert hota hai so...
        
        only one operation is performed i.e right rotation of the 1st imbalnced node
    
    right right insertion ka case 
        isme hamara newly inserted node root ke right ke right me hota hai so...

        only one opertation is performed i.e left rotation of the 1st imbalced node

    left right insertion ka case
        isme hamra 1st imbalced node ke left ke right me hota hai newly inseted node so...

        imse 2 operation performe hote hai 
        1. node->left i.e left child node of the 1st imbalced node / parent of the newly inseted node  is updated via left roataion 
            left rotation is done on this node
        
        2. now root node is right rotated and returned

    right left insertion ka case 
        isme hamra 1st imbalced node ke right ke left me hota hai newly inseted node so...

        isme 2 operations honge
        1. node->right  i.e right child node of the 1st imbalced node / parent of the newly inseted node  is updated via right roataion 

        2. node ka left rotation krke usko return kr do

*/
class node
{
public:
    int key;
    node *left;
    node *right;
    int height;
};

int getHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

node *createNode(int data)
{
    node *new_node = new node;
    new_node->key = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int getBalanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
/*
        left roatation
            y                 x
           / \               / \
          x   T3   <---    T1   y
        /   \                  / \
       T1    T2               T2  T3
*/
node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    //  rotation is done till here so update the height of x and y (affected nodes) also
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return y;
}
/*
        right roatation
            y                x
           / \              / \
          x   T3  --->    T1   y
        /   \                 / \
       T1    T2              T2  T3
*/
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    //  rotation is done till here so update the height of x and y (affected nodes) also
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    return x;
}

// finally the code for the insertion
node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    if (key < root->key)
    {
        //  we are updating the  root node here taki jb stack kahli ho to hme updated root node mile naki purana wala
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        //  we are updating the  root node here taki jb stack kahli ho to hme updated root node mile naki purana wala
        root->right = insert(root->right, key);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBalanceFactor(root);

    // from here all the rotation will be performed

    // left left --> bf>1 && root->left->key > key
    if (bf > 1 && root->left->key > key)
    {
        return rightRotate(root);
    }

    // right right --> bf<-1 && root->right->key < key
    if (bf < -1 && root->right->key < key)
    {
        return leftRotate(root);
    }

    // left right --> bf>1 && root->left->key < key
    if (bf > 1 && root->left->key < key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left --> bf<-1 && root->right->key > key
    if (bf < -1 && root->right->key > key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "Hello AVl Tree" << endl;

    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}