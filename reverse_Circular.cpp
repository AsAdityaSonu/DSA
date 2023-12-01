#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *InsertAtBeg(struct node **head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (!ptr)
    {
        return NULL;
    }
    ptr->data = data;
    if (*head == NULL)
    {
        ptr->link = ptr;
        *head = ptr;
    }
    else
    {
        struct node *temp = *head;
        while (temp->link != *head)
        {
            temp = temp->link;
        }
        temp->link = ptr;
        ptr->link = *head;
        *head = ptr;
    }
    return *head;
}

struct node *ReverseFromIndex2(struct node **head) {
    if (*head == NULL || (*head)->link == *head || (*head)->link->link == *head) {
        return *head;
    }

    struct node *prev = NULL, *current = (*head)->link, *next = NULL;

    while (current != *head) {
        prev = current;
        current = current->link;
    }

    do {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->link = prev;

    return *head;
}

void DisplayList(struct node *head)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->link;
    } while (temp != head);

    cout << endl;
}

int main()
{
    struct node *head = NULL;

    InsertAtBeg(&head, 7);
    InsertAtBeg(&head, 6);
    InsertAtBeg(&head, 1);
    InsertAtBeg(&head, 2);
    InsertAtBeg(&head, 3);
    InsertAtBeg(&head, 4);
    InsertAtBeg(&head, 5);

    cout << "Original Circular Linked List: ";
    DisplayList(head);

    ReverseFromIndex2(&head);

    cout << "Reversed Circular Linked List from Index 2: ";
    DisplayList(head);

    struct node *current = head;
    if (current != NULL)
    {
        struct node *temp;
        do
        {
            temp = current;
            current = current->link;
            free(temp);
        } while (current != head);
    }

    return 0;
}
