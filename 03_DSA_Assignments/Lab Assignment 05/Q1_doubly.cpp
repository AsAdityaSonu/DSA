#include <iostream>
#include <stdlib.h>
using namespace std;

// Self Referential structure
struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
};

struct dnode *CreateNode(int data)
{
    struct dnode *newNode = (struct dnode *)malloc(sizeof(struct dnode));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    return newNode;
}

void InsertAtBeg(struct dnode **head, int data)
{
    struct dnode *newNode = CreateNode(data);
    if (newNode != NULL)
    {
        if (*head != NULL)
        {
            (*head)->prev = newNode;
            newNode->next = *head;
        }
        *head = newNode;
    }
}

void InsertAtEnd(struct dnode **head, int data)
{
    struct dnode *newNode = CreateNode(data);
    struct dnode *temp = *head;

    if (newNode != NULL)
    {
        if (*head != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void InsertInBtw(struct dnode **head, int pos, int data){
    struct dnode *newNode = CreateNode(data);
    
    if(newNode !=NULL){
        if(*head != NULL){
            struct dnode *temp= *head;
            while(temp->data!=pos){
                temp=temp->next;
                cout<<temp->data<<endl;
            }

            

            newNode->prev=temp->prev;
            newNode->next= temp;
            temp->prev->next=newNode;
            temp->prev=newNode;

        }
    }
    
}

void DelBeg(dnode **head){
    struct dnode *temp;
    temp = (*head);
    *head= (*head)->next;
    free(temp);
}

void trav(struct dnode *head)
{
    struct dnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        (temp) = (temp)->next;
    }
    free(temp);
}

void freeDoublyLinkedList(struct dnode *head)
{
    while (head != NULL)
    {
        struct dnode *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct dnode *head;
    struct dnode *second;
    struct dnode *third;

    // Allocating memory dynamically
    head = (struct dnode *)malloc(sizeof(struct dnode));
    second = (struct dnode *)malloc(sizeof(struct dnode));
    third = (struct dnode *)malloc(sizeof(struct dnode));
    // cout<<sizeof(head)<<sizeof(second)<<sizeof(third)<<endl;

    head->prev = NULL;
    head->data = 10;
    head->next = second;

    second->prev = head;
    second->data = 20;
    second->next = third;

    third->prev = second;
    third->data = 30;
    third->next = NULL;

    // Menu
    int n;
    while (true)
    {
        cout << "------------------------------------------------------------------\n";
        cout << "1. Insert (begnning)\t2. Insertion (end)\t3. Insertion in between\n4. Deletion (beginning)\t5. Deletion (end)\t6. Deletion (specific dnode)\n7. Search (dnode) and display its position from head\n8. Display all the dnode values\t9. Exit" << endl;
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
            InsertInBtw(&head, 20, 3);
            break;

        // Deletion from the beginning
        case 4:
            DelBeg(&head);
            break;

        // Deletion from the end
        case 5:
            // DelEnd(&head);
            break;

        // Deletion of a specific dnode
        case 6:
            // DelInBtw(&head, 1);
            break;

        // Search & display
        case 7:
            // SearchPos(&head, 10);
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
    freeDoublyLinkedList(head);
    return 0;
}
