#include <iostream>
using namespace std;

class stack
{
public:
    int size = 0;
    int top = -1;
    int *arr;
};

int isEmpty(stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size -1)
    {
        return 1;
    }
    return 0;
    
}
int main()
{
    stack *s = new stack;
    s->size = 5;
    s->top = -1;
    s->arr = new int[s->size];
    s->arr[s->top+1] = 5;
    s->top++;

    s->arr[s->top+1] = 15;
    s->top++;
    s->arr[s->top+1] = 25;
    s->top++;
    s->arr[s->top+1] = 35;
    s->top++;
    if (isEmpty(s))
    {
        cout<<"the stack is Empty"<<endl;
    }
    else
    {
        cout<<"the stack is not Empty"<<endl;
    }
    if (isFull(s))
    {
        cout<<"the stack is full"<<endl;
    }
    else
    {
        cout<<"the stack is not full"<<endl;
    }
    
    

    return 0;
}