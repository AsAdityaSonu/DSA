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
    if (*head == NULL)
    {
        ptr->link = ptr; // Circular link to itself
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
    }
    return *head;
}

//size 
int FindSize(struct node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *temp = head;
    int size = 0;

    do
    {
        size++;
        temp = temp->link;
    } while (temp != head);

    return size;
}

int main()
{
    struct node *head = NULL;

    InsertAtEnd(&head, 20);
    InsertAtEnd(&head, 100);
    InsertAtEnd(&head, 40);
    InsertAtEnd(&head, 80);
    InsertAtEnd(&head, 60);

    int size = FindSize(head);
    cout << "Size of the Circular Linked List: " << size << endl;

    // Free memory before exiting
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
