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
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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
        cout << "Element " << i << ": " << head->data << endl;
        head = head->next;
        if (head->next == NULL)
        {
            cout << "Element " << i + 1 << ": " << head->data;
        }
    }
    cout << endl;
}

void delete_front(node **head)
{
    node *ptr = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(ptr);
}

void insert_at_index(node *head, int index, int data)
{
    node *new_node = new node(data);
    // new_node->data = data;
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else if (head->next == NULL)
    {
        head->next = new_node;
        new_node->prev = head;
        new_node->next = NULL;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            head = head->next;
        }
        cout << head->data;
        new_node->next = head->next;
        head->next->prev = new_node;
        head->next = new_node;
    }
}

int main()
{
    node *head = new node(1);
    node *head1 = new node(2);
    node *head2 = new node(3);
    node *head3 = new node(5);
    head->next = head1;
    head1->next = head2;
    head2->next = head3;
    head1->prev = head;
    head2->prev = head1;
    head3->prev = head2;
    insert_at_index(head, 3, 6);
    delete_front(&head);
    traversal(head);

    return 0;
}