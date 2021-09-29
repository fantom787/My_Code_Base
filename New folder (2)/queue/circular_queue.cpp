#include <iostream>
using namespace std;

class queue
{
public:
    int size;
    int f = 0;
    int b = 0;
    int *arr;
};

int isfull(queue *q)
{
    
    if (((q->b + 1) % q->size) == q->f)
    {
        cout << " Queue Is Full" << endl;
        return 1;
    }
    return 0;
}

int isempty(queue *q)
{
    if (q->f == q->b)
    {
        cout << " Queue Is Empty" << endl;
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data)
{
    if (isfull(q))
    {
        return;
    }
    q->b = (q->b + 1) % q->size;
    q->arr[q->b] = data;
}

int dequeue(queue *q)
{
    if (isempty(q))
    {
        return 0;
    }
    q->f = (q->f + 1) % q->size;
    return q->arr[q->f];
}

int main()
{
    queue *q = new queue;
    q->size = 10;
    q->arr = new int[q->size];
    enqueue(q, 10);
    cout << "Dequeue Element : " << dequeue(q) << endl;
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);
    enqueue(q, 15);
    enqueue(q, 16);
    enqueue(q, 17);
    enqueue(q, 18);
    enqueue(q, 28);
    enqueue(q, 38);
    enqueue(q, 38);
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;

    return 0;
}