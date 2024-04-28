#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left, *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

struct DLLNode {
  int data;
  DLLNode *prev, *next;

  DLLNode(int val) {
    data = val;
    prev = next = NULL;
  }
};

DLLNode* BSTToDLL(Node* root) {
  if (root == NULL)
    return NULL;

  static DLLNode *prev = NULL;
  DLLNode* head = BSTToDLL(root->left);

  DLLNode *node = new DLLNode(root->data);
  if (prev == NULL) 
    head = node;
  else {
    prev->next = node;
    node->prev = prev; 
  }
  prev = node;

  BSTToDLL(root->right);
  return head;
}

DLLNode* merge(DLLNode* first, DLLNode* second) {
  
  if (first == NULL)
    return second;

  if (second == NULL)
    return first;

  DLLNode* temp;
  if (first->data <= second->data) {
    temp = first;
    temp->next = merge(first->next, second);
  }
  else {
    temp = second;
    temp->next = merge(first, second->next); 
  }

  temp->next->prev = temp;
  temp->prev = NULL;

  return temp;
}

int main() {
  Node *root1 = new Node(5);
  root1->left = new Node(3);
  root1->right = new Node(6);
  root1->left->left = new Node(1); 
  root1->left->right = new Node(4);

  Node *root2 = new Node(7);
  root2->left = new Node(2);
  root2->right = new Node(8);

  DLLNode *head1 = BSTToDLL(root1);
  DLLNode *head2 = BSTToDLL(root2);

  DLLNode *head = merge(head1, head2);

  // Print merged list
  while(head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }

  return 0;
}
