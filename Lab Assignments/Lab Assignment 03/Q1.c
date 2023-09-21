#include <stdio.h>
#define MAX 100

struct stk
{
    int q[MAX];
    int top;
} s,p;

void init(struct stk *s)
{
    s->top = -1;
}

void isFull(struct stk s)
{
    if (s.top == MAX -1)
    {
        printf("full\n");
    }
    else
        printf("The stack is't full. :)\n");
}

void isEmpty(struct stk s)
{
    if (s.top == -1)
    {
        printf("the stack is empty :(\n");
    }
    else
        printf("The stack isn't empty. :)\n");
}

void push(struct stk *s, int n)
{
    if (s->top == MAX - 1)
    {
        printf("OVERFLOW");
    }
    else
    {
        s->top = s->top + 1;
        s->q[s->top] = n;
    }
}

int pop(struct stk *s)
{
    if (s->top == -1)
    {
        printf("UNDERFLOW\n");
        return NULL;
    }
    else
    {
        int item;
        item = s->q[s->top];
        s->top = s->top - 1;
        return item;
    }
}

void peek(struct stk *s)
{
    if (s->top == -1)
    {
        printf("Your stack is empty :(\n");
    }
    else
    {
        printf("%d\n", s->q[s->top]);
    }
}

void display(struct stk s)
{
    for (int i = s.top; i >= 0; i--)
    {
        printf("%d\n", pop(&s));
    }
}

int main()
{
    init(&s);
    int n;
    int c;

    while (1)
    {
        printf("------------------------------------\n");
        printf("1. PUSH\n2. POP\n3. isEmpty\n4. isFull\n5. DISPLAY\n6. PEEK\n7. Exit\n");
        printf("Choose any option: ");
        scanf("%d", &n);
        switch (n)
        {
        // PUSH
        case 1:

            printf("Enter number you wants to push...\n");
            scanf("%d", &c);
            push(&s, c);
            break;

        //  POP
        case 2:
            printf("%d", pop(&s));
            break;

        // isEmpty
        case 3:
            isEmpty(s);
            break;

        // isFull
        case 4:
            isFull(s);
            break;

        // Display
        case 5:
            display(s);
            break;

        // PEEK
        case 6:
            peek(&s);
            break;

        case 7:
            printf("Exiting...");
            return 0;

        default:
            printf("\nwrong option selected :(\n\n");
            break;
        }
    }
}