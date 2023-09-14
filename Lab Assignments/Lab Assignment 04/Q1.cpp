#include <iostream>
#define Max 100
using namespace std;

struct queue
{
    int pq[Max];
    int front, rear;
} p;

void init(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct queue *q, int x)
{
    if (q->rear == Max - 1)
    {
        cout << "OVERFLOW";
        return;
    }
    q->rear = q->rear + 1;
    q->pq[q->rear] = x;

    if (q->front == -1)
    {
        q->front = 0;
    }
}

int dequeue(struct queue *p)
{
    if (p->front == -1 || p->rear == -1)
    {
        cout << "Underflow";
        return -1;
    }
    int item;
    item = p->pq[p->front];
    p->front++;
    return item;
}

bool isEmpty(struct queue q)
{
    if (q.front == -1 && q.rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(struct queue q)
{
    if (q.rear == Max - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void display(struct queue q)
{
    if (!isEmpty(q))
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << dequeue(&q) << endl;
        }
    }
    else
    {
        cout << "The queue is Empty!!!" << endl;
    }
}

void peek(struct queue q)
{
    if (!isEmpty(q))
    {
        cout << q.pq[q.front] << endl;
    }
    else
    {
        cout << "The queue is Empty!!!" << endl;
    }
}

int main()
{
    init(&p);
    int n;
    int c;

    while (1)
    {
        cout << "------------------------------------------------------------------\n";
        cout << "1. ENQUEUE\t2. DEQUEUE\t3. isEmpty\t4. isFull\n5. DISPLAY\t6. PEEK\t\t7. Exit\n";
        cout << "Choose any option: ";
        cin >> n;
        cout << "------------------------------------------------------------------\n\n";
        switch (n)
        {
        // ENQUEUE
        case 1:

            // cout<<"Enter number you wants to push...\n";
            // cin>>c;
            enqueue(&p, 5);
            break;

        //  DEQUEUE
        case 2:
            cout << dequeue(&p) << endl;
            break;

        // isEmpty
        case 3:
            cout << isEmpty(p) << endl;
            break;

        // isFull
        case 4:
            cout << isFull(p) << endl;
            break;

        // Display
        case 5:
            display(p);
            break;

        // PEEK
        case 6:
            peek(p);
            break;

        case 7:
            cout << "Exiting...";
            return 0;

        default:
            cout << "\nwrong option selected :(\n\n";
            break;
        }
    }
    return 0;
}