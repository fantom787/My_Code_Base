#include <iostream>
using namespace std;

class queue
{
public:
    int size;
    int *arr;
    int b = -1;
};

int isfull(queue *q)
{
    if (q->b == q->size - 1)
    {
        cout << "*** Queue Is Full ***" << endl;
        return 1;
    }
    return 0;
}
int isempty(queue *q)
{
    if (q->b == -1)
    {
        cout << "*** Queue Is Empty ***" << endl;
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data)
{
    if (isfull(q))
    {
        cout << "Enqueue Unsucessfull" << endl;
        return;
    }
    q->b++;
    q->arr[q->b] = data;
}
int dequeue(queue *q)
{
    if (isempty(q))
    {
        cout << "Dequeue Unsucessfull" << endl;
        return 1;
    }
    int data = q->arr[0];
    for (int i = 0; i < q->b; i++)
    {
        q->arr[i] = q->arr[i + 1];
    }
    q->b--;
    return data;
}

main()
{
    queue *q = new queue;
    q->size = 5;
    q->arr = new int[q->size];
    enqueue(q, 5);
    enqueue(q, 7);
    enqueue(q, 6);
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    enqueue(q, 16);
    enqueue(q, 26);
    enqueue(q, 36);
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    cout << "Dequeue Element : " << dequeue(q) << endl;
    isempty(q);
    isfull(q);

    return 0;
}