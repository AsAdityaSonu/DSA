// Reverse STACK
#include <iostream>
using namespace std;
#define MAX 100

struct stk
{
    char stack[MAX];
    char rev[MAX];
    int top;
} s;

void init(struct stk *p)
{
    p->top = -1;
}

void push(struct stk *p, char *c)
{
    if (p->top == p->top - 1)
    {
        cout << "OVERFLOW";
    }
    p->top++;
    p->stack[p->top] = *c;
    cout << p->stack[p->top] << "\t";
}

int pop(struct stk *s)
{
    if (s->top == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        int item;
        item = s->stack[s->top];
        s->top = s->top - 1;
        return item;
    }
}

char *rev(struct stk *p)
{
    for (int i = 0; i < 10; i++)
    {
        p->rev[i] = p->stack[9 - i];
        // cout<<p->rev[i]<<"\t";
    }

    return p->rev;
}

int main()
{
    init(&s);
    char c = 'A';
    for (int i = 0; i < 10; i++)
    {
        push(&s, &c);
        c++;
    }
    cout << "\n";
    rev(&s);

    cout << rev(&s) << "\n\n";

    return 0;
}