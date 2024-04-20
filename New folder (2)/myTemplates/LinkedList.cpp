struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
struct LinkedList
{
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(Node *delnode) // delete the current node
    {
        Node *prevv = delnode->prev;
        Node *nextt = delnode->next;
        prevv->next = nextt;
        nextt->prev = prevv;
    }
    void addNode(Node *newnode, Node *tail) // add the new node before the given node
    {
        tail->prev->next = newnode;
        newnode->prev = tail->prev;
        newnode->next = tail;
        tail->prev = newnode;
    }
    void print()
    {
        for (Node *it = head->next; it != tail; it = it->next)
        {
            cout << it->val << " ";
        }
        cout << endl;
    }
};