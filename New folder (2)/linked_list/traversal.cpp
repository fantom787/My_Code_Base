#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void linked_list_traversal(node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element :" << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    head->data = 50;
    head->next = second;
    second->data=69;
    second->next=third;
    third->data=5;
    third->next = fourth;
    fourth->data=78;
    fourth->next = NULL;
    linked_list_traversal(head); 
    return 0;
}