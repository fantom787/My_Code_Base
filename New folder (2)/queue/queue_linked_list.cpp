#include <iostream>
using namespace std;

class queue
{
public:
    int data;
    queue *next;
};

void linkedlisttraversal(queue *q)
{
    cout << "printing the  elements of linked list" << endl;
    while (q != NULL)
    {
        cout << " Element :" << q->data << endl;
        q = q->next;
    }
}

int isfull(queue *q)
{
    queue *ptr = new queue;
    if (ptr == NULL)
    {
        cout << "Queue Is Full" << endl;
        return 1;
    }
    return 0;
}
int isempty(queue *q)
{
    if (q->next == NULL)
    {
        cout << "Queue Is Empty" << endl;
        return 1;
    }
    return 0;
}
void enqueue(queue **front, queue **back, int data)
{
    if (isfull(*front))
    {
        return;
    }
    else
    {
        queue *new1 = new queue;
        new1->data = data;
        new1->next = NULL;
        if (*front == NULL)
        {
            *front = *back = new1;
        }
        else
        {
            (*back)->next = new1;
            *back = new1;
        }
    }
}
int dequeue(queue **front)
{
    if (isempty(*front))
    {
        return 0;
    }
    queue *ptr = *front;
    int data = (*front)->data;
    *front = (*front)->next;
    free(ptr);
    return data;
}
int main()
{
    queue *front = NULL;
    queue *back = NULL;
    enqueue(&front, &back, 45);
    enqueue(&front, &back, 47);
    enqueue(&front, &back, 48);
    enqueue(&front, &back, 48);
    enqueue(&front, &back, 48);
    enqueue(&front, &back, 48);
    enqueue(&front, &back, 48);
    linkedlisttraversal(front);
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    cout<<"dequeue element :"<<dequeue(&front)<<endl;
    linkedlisttraversal(front);

    return 0;
}