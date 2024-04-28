#include <iostream>
using namespace std;

struct TNode
{
    struct TNode *left;
    int data;
    struct TNode *right;
    TNode(int data) : left(NULL), data(data), right(NULL){};
};

TNode *searchRecursive(TNode *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchRecursive(root->left, key);
    }
    else
    {
        return searchRecursive(root->right, key);
    }
}

TNode *searchItr(TNode *root, int key)
{
    TNode *temp = root;

    while (temp)
    {
        if (temp->data == key)
        {
            return temp;
        }
        else if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return nullptr;
}

TNode* findMin(TNode* node) {
    TNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

TNode* findMax(TNode* node) {
    TNode* current = node;
    while (current && current->right != nullptr) {
        current = current->right;
    }
    return current;
}

TNode* inorderSuccessor(TNode* root, int key) {
    TNode* current = searchItr(root, key);
    if (current == nullptr) {
        return nullptr;
    }

    // Case 1: Node has a right subtree
    if (current->right != nullptr) {
        return findMin(current->right);
    }

    // Case 2: Node doesn't have a right subtree
    TNode* successor = nullptr;
    TNode* ancestor = root;
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }

    return successor;
}

TNode* inorderPredecessor(TNode* root, int key) {
    TNode* current = searchItr(root, key);
    if (current == nullptr) {
        return nullptr;
    }

    // Case 1: Node has a left subtree
    if (current->left != nullptr) {
        return findMax(current->left);
    }

    // Case 2: Node doesn't have a left subtree
    TNode* predecessor = nullptr;
    TNode* ancestor = root;
    while (ancestor != current) {
        if (current->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}

// Max Ele
int MaxEle(TNode *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    int leftMax = MaxEle(root->left);
    int rightMax = MaxEle(root->right);

    int maximum = max(root->data, max(leftMax, rightMax));
    return maximum;
}

int MinEle(TNode *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    int leftMin = MinEle(root->left);
    int rightMin = MinEle(root->right);

    cout << "-------------------" << endl;
    cout << leftMin << endl;
    cout << rightMin << endl;

    cout << "---------||----------" << endl;

    int minimum = min(root->data, min(leftMin, rightMin));
    return minimum;
}

int main()
{
    TNode *root = new TNode(50);
    root->left = new TNode(40);
    root->right = new TNode(60);
    root->left->left = new TNode(20);
    root->left->right = new TNode(45);
    root->right->left = new TNode(55);
    root->right->right = new TNode(70);

    // Recursive Fun
    int key = 55;
    TNode *found = searchRecursive(root, key);
    if (found)
    {
        cout << "Found " << key << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // Iter..
    // int key2 = 40;
    // TNode *found2 = searchItr(root, key2);
    // if (found2)
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not Found" << endl;
    // }

    // Max Ele..
    // int max = MaxEle(root);
    // cout << "max ele is: " << max << endl;

    // Min Ele..
    int min = MinEle(root);
    cout << "min ele is: " << min << endl;

    // Inorder Successor
    int key_successor = 40;
    TNode* successorNode = inorderSuccessor(root, key_successor);
    if (successorNode != nullptr) {
        cout << "Inorder Successor of " << key_successor << " is: " << successorNode->data << endl;
    } else {
        cout << "No Inorder Successor found for " << key_successor << endl;
    }

    // Inorder Predecessor
    int key_predecessor = 55;
    TNode* predecessorNode = inorderPredecessor(root, key_predecessor);
    if (predecessorNode != nullptr) {
        cout << "Inorder Predecessor of " << key_predecessor << " is: " << predecessorNode->data << endl;
    } else {
        cout << "No Inorder Predecessor found for " << key_predecessor << endl;
    }

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
