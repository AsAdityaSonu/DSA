#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

int countAndDelete(struct node **head, int key)
{
    struct node *current = *head;
    struct node *prev = nullptr;
    int count = 0;

    while (current != nullptr)
    {
        if (current->data == key)
        {
            if (prev == nullptr)
            {
                // first node
                *head = current->link;
                delete current;
                current = *head;
            }
            else
            {
                prev->link = current->link;
                delete current;
                current = prev->link;
            }
            count++;
        }
        else
        {
            prev = current;
            current = current->link;
        }
    }

    return count;
}

int main()
{
    struct node *head = nullptr;
    struct node *second = nullptr;
    struct node *third = nullptr;
    struct node *fourth = nullptr;
    struct node *fifth = nullptr;
    struct node *sixth = nullptr;
    struct node *seventh = nullptr;

    // Create nodes and assign data
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;
    fifth = new node;
    sixth = new node;
    seventh = new node;

    head->data = 1;
    second->data = 2;
    third->data = 1;
    fourth->data = 2;
    fifth->data = 1;
    sixth->data = 3;
    seventh->data = 1;

    // Linking
    head->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = sixth;
    sixth->link = seventh;
    seventh->link = nullptr;

    // search and delete
    int key = 1;

    int count = countAndDelete(&head, key);

    cout << "Number of occurrences of key " << key << " is: " << count << endl;

    // Print the modified linked list
    struct node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->link;
    }
    cout << endl;

    return 0;
}
