#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int data)
    {
        
    }
};
void traversal(node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    int i = 0;
    while (head->next != NULL)
    {
        i++;
        cout << "Element : " << i << " " << head->data << endl;
        head = head->next;
        if (head->next == NULL)
        {
            cout << "Element : " << i + 1 << " " << head->data << endl;
        }
    }
    cout << endl;
}

void delete_front(node *head)
{
    node *prev = head;
    head = head->next;
    head = head->next;
    head->prev = NULL;
    free(prev);
}

void insert_at_index(node *head, int index, int data)
{
    node *new_node = new node;
    new_node->data = data;
    for (int i = 0; i < index - 1; i++)
    {
        head = head->next;
    }
    head->next->prev = new_node;
    head->next = new_node;
    new_node->prev = head;
}

int main()
{
    node *head = new node;
    insert_at_index(head, 1, 5);

    return 0;
}