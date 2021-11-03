#include <iostream>
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
        cout << "Element " << i + 1 << " :" << ptr->data << endl;
        ptr = ptr->next;
        i++;
    }
    cout << endl;
}

void delete_first(node **head)
{
    node *ptr = *head;
    *head = (*head)->next;
    free(ptr);
}
void delete_end(node *head)
{
    node *p = head;
    node *q = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    for (int j = 0; j < i - 1; j++)
    {
        q = q->next;
    }
    q->next = NULL;
    free(p);
}
void delete_given(node *ptr, node *head)
{
    int i = 0;
    node *p = head;
    while (p->data != ptr->data)
    {
        p = p->next;
        i++;
    }
    for (int j = 0; j < i - 1; j++)
    {
        head = head->next;
    }

    head->next = ptr->next;
    free(p);
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
    delete_first(&head);
    // delete_end(head);
    // delete_given(third, head)
    list_traversal(head);
    return 0;
}