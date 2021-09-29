#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top = -1;
    int *arr;
};

int isFull(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s,int data)
{
    if(isFull(s))
    {
        cout<<"Stackoverflow"<<endl;
        return;
    }
    else
    {
        s->arr[s->top+1] = data;
        s->top++;
    }
}

int pop(stack *s)
{
    if(isEmpty(s))
    {
        cout<<"StackUnderflow"<<endl;
        return 404;
    }
    else
    {
        int element = s->arr[s->top];
        s->top--;
        return element;
    }
}
int peek(stack *s , int index)
{
    int Inindex = s->top - index +1;
    if (Inindex < 0)
    {
        cout<<"Invalid Index"<<endl;
        return 101;
    }
    else
    {
        return s->arr[Inindex];
    }

}

int main()
{
    stack *s = new stack;
    s->size = 50;
    s->arr = new int[s->size];
    push(s,5);
    push(s,15);
    push(s,25);
    push(s,35);
    push(s,35);
    push(s,35);
    push(s,35);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    for (int i = 1 ; i <= s->top+1; i++)
    {
        cout<<"The Element at Index "<<i<<" is "<<peek(s,i)<<endl;
    }
    
   
    
    return 0;
}