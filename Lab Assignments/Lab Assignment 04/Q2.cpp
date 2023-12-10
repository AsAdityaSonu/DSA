#include <iostream>
#define Max 3
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

bool isEmpty(struct queue q)
{
    return (q.front == -1);
}

bool isFull(struct queue q)
{
    return ((q.rear + 1) % Max == q.front);
}

void enqueue(struct queue *q, int x)
{
    if (isFull(*q))
    {
        cout << "OVERFLOW" << endl;
        return;
    }

    if (isEmpty(*q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % Max; // Circular increment
    }

    q->pq[q->rear] = x;
}

int dequeue(struct queue *q)
{
    if (isEmpty(*q))
    {
        cout << "Underflow" << endl;
        return -1;
    }

    int item = q->pq[q->front];
    
    if (q->front == q->rear)
    {
        // If there is only one element
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % Max; // Circular increment
    }

    return item;
}

void display(struct queue q)
{
    if (isEmpty(q))
    {
        cout << "The queue is Empty!!!" << endl;
    }
    else
    {
        int i = q.front;
        do
        {
            cout << q.pq[i] << endl;
            i = (i + 1) % Max; // Circular increment
        } while (i != (q.rear + 1) % Max);
    }
}

void peek(struct queue q)
{
    if (isEmpty(q))
    {
        cout << "The queue is Empty!!!" << endl;
    }
    else
    {
        cout << "Peek element: " << q.pq[q.front] << endl;
    }
}

int main()
{
    init(&p);
    int n;

    while (1)
    {
        cout << "------------------------------------------------------------------\n";
        cout << "1. ENQUEUE\t2. DEQUEUE\t3. isEmpty\t4. isFull\n5. DISPLAY\t6. PEEK\t7. Exit\n";
        cout << "Choose any option: ";
        cin >> n;
        cout << "------------------------------------------------------------------\n\n";
        switch (n)
        {
        // ENQUEUE
        case 1:
            int c;
            cout << "Enter number you want to push: ";
            cin >> c;
            enqueue(&p, c);
            break;

        // DEQUEUE
        case 2:
            cout << "Dequeued element: " << dequeue(&p) << endl;
            break;

        // isEmpty
        case 3:
            cout << "Queue is empty: " << (isEmpty(p) ? "Yes" : "No") << endl;
            break;

        // isFull
        case 4:
            cout << "Queue is full: " << (isFull(p) ? "Yes" : "No") << endl;
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
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "\nWrong option selected :(\n\n";
            break;
        }
    }
    return 0;
}
