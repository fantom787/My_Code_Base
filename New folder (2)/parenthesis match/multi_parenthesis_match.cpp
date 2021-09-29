#include <iostream>
using namespace std;

class stack
{
public:
    int size;
    int top = -1;
    char *arr;
};

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }

    return 0;
}

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
    char popped_char;
    stack *s = new stack;
    s->size = length;
    s->arr = new char[length];
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (isEmpty(s))
            {
                return 0;
            }
            popped_char = pop(s);
            if (!match(popped_char, str[i]))
            {
                return 0;
            }
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
    char exp[] = "[4-6]((8){(9-8)})";
    int size = sizeof(exp);

    if (paramatch(exp, size))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }

    return 0;
}