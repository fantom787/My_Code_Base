#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
};

void linkedlisttraversal(node *top)
{
    while (top != NULL)
    {
        cout<<"Element : "<<top->data<<endl;
        top = top->next;
    }
    cout<<endl;
}
int Isfull(node *top)
{
    node *ptr = new node;
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}
int Isempty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(node **top, int data)
{
    if (Isfull(*top))
    {
        cout << "Stack OverFlow" << endl;
    }
    else
    {
        node *ptr = new node;
        ptr->data = data;
        ptr->next = *top;
        *top = ptr;
    }
}


int pop(node **top)
{
    if (Isempty(*top))
    {
        cout<<"Stack UnderFlow"<<endl;
        return 404;
    }
    else
    {
        node *ptr = *top;
        int data  = ptr->data;
        *top = ptr->next;
        free(ptr);
        return data;
    }
}

int peek(node *top , int index)
{
    node *ptr = top;
    for (int  i = 0; ( i < index-1 && ptr != NULL ); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        cout<<"Wrong index"<<endl;
        return 404;
    }
}
int stackTop(node *top)
{
    return top->data;
}
int stackbottom(node *top)
{
    node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    node *top =NULL;
    push(&top,5);
    push(&top,15);
    push(&top,55);
    push(&top,25);
    push(&top,35);
    push(&top,45);
    linkedlisttraversal(top);
    cout<<pop(&top)<<endl;
    cout<<pop(&top)<<endl;
    cout<<pop(&top)<<endl;
    linkedlisttraversal(top);
    cout<<peek(top,1)<<endl;
    cout<<peek(top,2)<<endl;
    cout<<peek(top,3)<<endl;
    cout<<peek(top,4)<<endl;
    cout<<stackTop(top)<<endl;
    cout<<stackbottom(top)<<endl;

    return 0;
}