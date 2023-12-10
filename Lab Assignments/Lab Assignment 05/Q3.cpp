#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node* findMiddle(struct node *head)
{
    if (head == nullptr)
        return nullptr;

    struct node *slow = head;
    struct node *fast = head;

    while (fast != nullptr && fast->link != nullptr)
    {
        slow = slow->link;
        fast = fast->link->link;
    }

    return slow;
}

int main()
{
    struct node *head = nullptr;
    struct node *second = nullptr;
    struct node *third = nullptr;
    struct node *fourth = nullptr;
    struct node *fifth = nullptr;

    // Create nodes and assign data
    head = new node;
    second = new node;
    third = new node;
    fourth = new node;
    fifth = new node;

    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    fifth->data = 5;

    // Linking
    head->link = second;
    second->link = third;
    third->link = fourth;
    fourth->link = fifth;
    fifth->link = nullptr;

    // Find the middle 
    struct node *middle = findMiddle(head);

    if (middle != nullptr)
        cout << "The middle of the linked list is: " << middle->data << endl;
    else
        cout << "The list is empty." << endl;

    return 0;
}
