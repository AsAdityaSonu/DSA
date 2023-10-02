#include <iostream>
#include <stdlib.h>
using namespace std;

// Self Referential structure
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
        *head = ptr;
    }
    return *head;
}

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

struct node *InsertAfter(struct node **head, int afterData, int data)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return *head;
    }

    struct node *temp = *head;
    do
    {
        if (temp->data == afterData)
        {
            struct node *ptr = (struct node *)malloc(sizeof(struct node));
            if (!ptr)
            {
                return *head;
            }
            ptr->data = data;
            ptr->link = temp->link;
            temp->link = ptr;
            return *head;
        }
        temp = temp->link;
    } while (temp != *head);

    cout << "Node with data " << afterData << " not found in the list." << endl;
    return *head;
}

struct node *DeleteNode(struct node **head, int data)
{
    if (*head == NULL)
    {
        cout << "List is empty." << endl;
        return *head;
    }

    struct node *current = *head, *prev = NULL;

    do
    {
        if (current->data == data)
        {
            if (prev == NULL) // Node to be deleted is the head
            {
                struct node *temp = *head;
                while (temp->link != *head)
                {
                    temp = temp->link;
                }
                if (*head == temp) // If there is only one node in the list
                {
                    *head = NULL;
                }
                else
                {
                    *head = (*head)->link;
                    temp->link = *head;
                }
                free(current);
                return *head;
            }
            prev->link = current->link;
            free(current);
            return *head;
        }
        prev = current;
        current = current->link;
    } while (current != *head);

    cout << "Node with data " << data << " not found in the list." << endl;
    return *head;
}

void SearchNode(struct node *head, int data)
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct node *temp = head;
    int position = 0;
    bool found = false;

    do
    {
        if (temp->data == data)
        {
            found = true;
            break;
        }

        temp = temp->link;
        position++;
    } while (temp != head);

    if (found)
    {
        cout << "Node with data " << data << " found at position " << position << " in the Circular Linked List." << endl;
    }
    else
    {
        cout << "Node with data " << data << " not found in the Circular Linked List." << endl;
    }
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

    // Menu
    int choice, data, afterData;

    do
    {
        cout << "------------------------------------------------------------------\n";
        cout << "1. Insert at the beginning\n2. Insert at the end\n3. Insert after a specific node\n";
        cout << "4. Delete a specific node\n5. Search for a node\n6. Display the Circular Linked List\n7. Exit\n";
        cout << "------------------------------------------------------------------\n";
        cout << "Please select an option from the menu: ";
        cin >> choice;
        cout << "------------------------------------------------------------------\n";

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at the beginning: ";
            cin >> data;
            InsertAtBeg(&head, data);
            break;

        case 2:
            cout << "Enter data to insert at the end: ";
            cin >> data;
            InsertAtEnd(&head, data);
            break;

        case 3:
            cout << "Enter data to insert: ";
            cin >> data;
            cout << "Enter the data after which you want to insert: ";
            cin >> afterData;
            InsertAfter(&head, afterData, data);
            break;

        case 4:
            cout << "Enter data to delete: ";
            cin >> data;
            DeleteNode(&head, data);
            break;

        case 5:
            cout << "Enter data to search: ";
            cin >> data;
            SearchNode(head, data);
            break;

        case 6:
            cout << "Circular Linked List: ";
            DisplayList(head);
            break;

        case 7:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 7);

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
