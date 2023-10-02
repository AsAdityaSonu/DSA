#include <iostream>
#include <stdlib.h>
using namespace std;

// Self Referential structure
struct node
{
    int data;
    struct node *link;
};


struct node *InsertAtEnd(struct node **head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (!ptr)
    {
        return NULL;
    }
    ptr->data = data;
    ptr->link = NULL;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        struct node *temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
    return *head;
}

bool IsCircular(struct node *head)
{
    if (head == NULL)
    {
        return false;
    }

    struct node *slowPtr = head;
    struct node *fastPtr = head;

    while (fastPtr != NULL && fastPtr->link != NULL)
    {
        slowPtr = slowPtr->link;         
        fastPtr = fastPtr->link->link;  

        if (slowPtr == fastPtr)
        {
            return true;  
        }
    }

    return false;  // If fastPtr reaches the end
}

int main()
{
    struct node *head = NULL;

    InsertAtEnd(&head, 20);
    InsertAtEnd(&head, 100);
    InsertAtEnd(&head, 40);
    InsertAtEnd(&head, 80);
    InsertAtEnd(&head, 60);

    struct node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = head;

    // Check
    if (IsCircular(head))
    {
        cout << "The linked list is a circular linked list." << endl;
    }
    else
    {
        cout << "The linked list is not a circular linked list." << endl;
    }

    // Free memory before exiting
    temp = head;
    if (temp != NULL)
    {
        struct node *nextNode;
        do
        {
            nextNode = temp->link;
            free(temp);
            temp = nextNode;
        } while (temp != head);
    }

    return 0;
}
