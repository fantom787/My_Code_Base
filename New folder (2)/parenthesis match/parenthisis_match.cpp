#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top = -1;
    char *arr;
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
void push(stack *s, char data)
{
    if (isFull(s))
    {
        cout << "Stackoverflow" << endl;
        return;
    }
    else
    {
        s->arr[s->top + 1] = data;
        s->top++;
    }
}

char pop(stack *s)
{
    if (isEmpty(s))
    {
        cout << "StackUnderflow" << endl;
        return -1;
    }
    else
    {
        int element = s->arr[s->top];
        s->top--;
        return element;
    }
}

int paramatch(char *str, int length)
{
    stack *s = new stack;
    s->size = length;
    s->arr = new char[length];
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')')
        {
            pop(s);
        }
    }
    if (isEmpty(s))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char exp[] = "((8)(*--$$9)))";
    // Check if stack is empty
    int size = sizeof(exp);
    if (paramatch(exp,size))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }

    return 0;
}