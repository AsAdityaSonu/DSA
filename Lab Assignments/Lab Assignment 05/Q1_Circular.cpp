#include <iostream>
#include <stdlib.h>
using namespace std;

// Self Referential structure
struct cnode
{
    int data;
    struct cnode *link;
};

struct cnode *InsertAtBeg(struct cnode **head, int data)
{
    struct cnode *ptr = (struct cnode *)malloc(sizeof(struct cnode));
    if (!ptr)
    {
        return NULL;
    }
    ptr->data = data;
    ptr->link = *head;
    *head = ptr;
    return *head;
}

struct cnode *InsertAtEnd(struct cnode **head, int data)
{
    struct cnode *ptr = (struct cnode *)malloc(sizeof(struct cnode));
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
        struct cnode *temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
    return ptr;
}

struct cnode *InsertInBtw(struct cnode **head, int index, int data)
{
    if (index == 0)
    {
        InsertAtBeg(head, data);
        return 0;
    }

    struct cnode *ptr = (struct cnode *)malloc(sizeof(struct cnode));
    if (!ptr)
    {
        // Memory allocation failed
        return *head;
    }

    struct cnode *temp = *head;
    int i = 0;

    while (i != index - 1 && temp != NULL)
    {
        temp = temp->link;
        i++;
    }
    ptr->data = data;
    ptr->link = temp->link;
    temp->link = ptr;

    return ptr;
}

void DelBeg(struct cnode **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct cnode *temp = *head;
    *head = (*head)->link;
    free(temp);
}

void DelEnd(struct cnode **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct cnode *temp = *head;
    struct cnode *prev = NULL;

    // Traverse the list to find the last cnode
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    // If prev is NULL
    if (prev == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        prev->link = NULL;
        free(temp);
    }
}

void DelInBtw(struct cnode **head, int index)
{
    if (*head == NULL || index < 0)
    {
        return;
    }

    if (index == 0)
    {
        DelBeg(head);
        return;
    }

    struct cnode *temp = *head;
    struct cnode *prev = NULL;
    int i = 0;

    while (temp != NULL && i != index)
    {
        prev = temp;
        temp = temp->link;
        i++;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->link = temp->link;

    free(temp);
}

void SearchPos(struct cnode **head, int data)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct cnode *temp = *head;
    int position = 0;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            found = true;
            break;
        }

        temp = temp->link;
        position++;
    }

    if (found)
    {
        cout << "cnode with data " << data << " found at position " << position << " from the head." << endl;
    }
    else
    {
        cout << "cnode with data " << data << " not found in the list." << endl;
    }
}


void trav(struct cnode *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

int main()
{
    struct cnode *head;
    struct cnode *second;
    struct cnode *third;

    // Allocating memory dynamically
    head = (struct cnode *)malloc(sizeof(struct cnode));
    second = (struct cnode *)malloc(sizeof(struct cnode));
    third = (struct cnode *)malloc(sizeof(struct cnode));
    // cout<<sizeof(head)<<sizeof(second)<<sizeof(third)<<endl;
    // Linking first with second
    head->data = 10;
    head->link = second;

    // Linking second with third
    second->data = 20;
    second->link = third;

    // Linking third
    third->data = 30;
    third->link = NULL;

    // Menu
    int n;
    while (true)
    {
        cout << "------------------------------------------------------------------\n";
        cout << "1. Insert (begnning)\t2. Insertion (end)\t3. Insertion in between\n4. Deletion (beginning)\t5. Deletion (end)\t6. Deletion (specific cnode)\n7. Search (cnode) and display its position from head\n8. Display all the cnode values\t9. Exit" << endl;
        cout << "------------------------------------------------------------------\n";
        cout << "Please select any option from above: ";
        cin >> n;
        cout << "------------------------------------------------------------------\n";

        switch (n)
        {
        // Insert at the begnning
        case 1:
            InsertAtBeg(&head, 12);
            break;

        // Insertion at the end
        case 2:
            InsertAtEnd(&head, 15);
            break;

        // Insertion in between
        case 3:
            InsertInBtw(&head, 2, 3);
            break;

        // Deletion from the beginning
        case 4:
            DelBeg(&head);
            break;

        // Deletion from the end
        case 5:
            DelEnd(&head);
            break;

        // Deletion of a specific cnode
        case 6:
            DelInBtw(&head, 1);
            break;

        // Search & display 
        case 7:
            SearchPos(&head, 10);
            break;

        // Display
        case 8:
            trav(head);
            break;

        case 9:
            free(head);
            free(second);
            free(third);
            cout << "Exiting..." << endl;
            return 0;
            break;
        default:
            cout << "Please select right option :)" << endl;
            break;
        }
    }
    return 0;
}
