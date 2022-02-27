#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
void list_traversal(node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
        i++;
    }
    cout << endl;
}
void add_starting(node **ptr, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *ptr;
    *ptr = new_node;
}
void add_end(node *ptr, int data)
{
    node *ptr1 = (node *)malloc(sizeof(int));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr1->data = data;
    ptr1->next = ptr->next;
    ptr->next = ptr1;
}
void add_after(int data, int index, node *head)
{
    int i = 0;
    while (i != index - 1)
    {
        head = head->next;
        i++;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head->next;
    head->next = ptr;
}
void insert_after(int data, node *ptr)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = data;
    p->next = ptr->next;
    ptr->next = p;
}

void reverse(node **head)
{
    node *curr = (*head);
    if (curr == NULL || curr->next == NULL)
        return;
    node *prev = NULL;
    while(curr!=NULL)
    {
        node*frwd = curr->next;
        curr->next=prev;
        prev = curr;
        curr = frwd;
    }
    (*head)=prev;
}

int main()
{

    node *head;
    node *second;
    node *third;
    node *fourth;
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    head->data = 50;
    head->next = second;
    second->data = 39;
    second->next = third;
    third->data = 5;
    third->next = fourth;
    fourth->data = 78;
    fourth->next = NULL;
    add_starting(&head, 69);
    add_starting(&head, 99);
    add_end(head, 12);
    add_after(7, 2, head);
    insert_after(7, second);
    list_traversal(head);
    reverse(&head);
    list_traversal(head);
    return 0;
}