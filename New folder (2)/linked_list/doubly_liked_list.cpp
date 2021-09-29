#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
};

void traversal(node *head)
{
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
    while (head->prev != NULL)
    {
        cout << "Element : " << i + 1 << " " << head->data << endl;
        head = head->prev;
        i--;
        if (head->prev == NULL)
        {
            cout << "Element : " << i + 1 << " " << head->data << endl;
        }
    }
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));

    head->data = 5;
    head->prev = NULL;
    head->next = second;

    second->data = 15;
    second->prev = head;
    second->next = third;

    third->data = 25;
    third->prev = second;
    third->next = fourth;

    fourth->data = 35;
    fourth->prev = third;
    fourth->next = NULL;

    traversal(head);

    return 0;
}