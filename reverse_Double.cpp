#include <iostream>
using namespace std;

struct dnode
{
    struct dnode *prev;
    int data;
    struct dnode *next;
    dnode(int val) : prev(nullptr), data(val), next(nullptr) {}
};

struct dnode *CreateNode(int data)
{
    return new dnode(data);
}

void ReverseFromIndex2(struct dnode **head)
{
    if (*head == nullptr || (*head)->next == nullptr || (*head)->next->next == nullptr)
    {
        cout << "Not enough elements to reverse starting from index 2." << endl;
        return;
    }

    struct dnode *current = *head;
    int count = 1;

    while (count < 2 && current != nullptr)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
    {
        cout << "Index 2 not found." << endl;
        return;
    }

    struct dnode *prev = nullptr;
    struct dnode *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    if (count == 2)
    {
        (*head)->next->prev = nullptr;
        *head = prev;
    }
}

int main()
{
    struct dnode *head;
    struct dnode *second;
    struct dnode *third;
    struct dnode *fourth;
    struct dnode *fifth;
    struct dnode *sixth;
    struct dnode *seventh;

    // Allocating memory dynamically
    head = CreateNode(5);
    second = CreateNode(4);
    third = CreateNode(3);
    fourth = CreateNode(2);
    fifth = CreateNode(1);
    sixth = CreateNode(6);
    seventh = CreateNode(7);

    // Linking nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;
    fifth->next = sixth;
    sixth->prev = fifth;
    sixth->next = seventh;
    seventh->prev = sixth;
    seventh->next = nullptr;

    // Example: Reverse elements starting from index 2
    ReverseFromIndex2(&head);

    // Add more operations or display the reversed list here

    return 0;
}
