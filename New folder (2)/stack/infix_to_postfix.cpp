/*
    bahut simple hai 
    dekho sbse pehle postfix wala array create kr lo infix ke barabar length ka 
    fir ye wale steps follow kro
    1. agr wo operator nhi hai to array me daal do aur infix nd postfix pointer age bda do
    2. agr wo operator hai to check kro uski precedece stack top se agr jyada hui to push kr do aur infix ko agr bda do
    3. agr nhi hai to pop kr do aur postfix ko age bda do
    4. last me agr kuch bachta hai to usko fir postfix wale array me pop krke daal do
    hai na simple!!!!
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
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
char stacktop(stack *s)
{
    return s->arr[s->top];
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }

    if (a == '/' || a == '*')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    return -1;
}

char *postfix(char *infix)
{
    stack *s = new stack;
    s->size = strlen(infix);
    s->arr = new char[s->size];
    int i = 0; // track inifix traversal
    int j = 0; // track posfix traversal
    char *pos = new char[strlen(infix)];
    while (infix[i] != '\0')
    {

        if (!isOperator(infix[i]))
        {
            pos[j] = infix[i];
            j++;
            i++;
        }
        
        else
        {

            if (precedence(infix[i]) > precedence(stacktop(s)))
            {
                push(s, infix[i]);
                i++;
            }
            else
            {
                pos[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        pos[j] = pop(s);
        j++;
    }
    pos[j] = '\0';
    return pos;
}

int main()
{

    char infix[] = "(a+b)*c/d";
    printf("postfix is %s", postfix(infix));

    return 0;
}