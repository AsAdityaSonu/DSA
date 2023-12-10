#include <iostream>
#include <stack>
using namespace std;

struct TNode {
    struct TNode* left;
    int data;
    struct TNode* right;
    TNode(int data) : left(NULL), data(data), right(NULL) {};
};

void inOrderTraversal(TNode* root) {
    if (root == nullptr) {
        return;
    }

    stack<TNode*> nodeStack;
    TNode* current = root;

    while (current != nullptr || !nodeStack.empty()) {
        // Traverse to the leftmost node while pushing nodes onto the stack
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        // Process the current node (pop and print)
        current = nodeStack.top();
        nodeStack.pop();
        cout << current->data << " ";

        // Move to the right subtree
        current = current->right;
    }
}

int main() {
    TNode* root = new TNode(50);
    root->left = new TNode(40);
    root->right = new TNode(60);
    root->left->left = new TNode(20);
    root->left->right = new TNode(45);
    root->right->left = new TNode(55);
    root->right->right = new TNode(70);

    cout << "In-order traversal using stack: ";
    inOrderTraversal(root);

    // Delete the tree nodes (as in your previous code)
    delete root->right->right;
    delete root->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;
    root = nullptr;

    return 0;
}
