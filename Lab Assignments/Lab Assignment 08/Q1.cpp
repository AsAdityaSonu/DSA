#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode
{
    struct TreeNode *left;
    int data;
    struct TreeNode *right;

    TreeNode(int value) : left(NULL), data(value), right(NULL){};
};

void preorderTraversal(TreeNode *root) {
    if (root) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "------------------------------------------------------------------\n";
    preorderTraversal(root);
    cout << endl;
    
    cout << "------------------------------------------------------------------\n";
    inorderTraversal(root);
    cout << endl;

    cout << "------------------------------------------------------------------\n";
    postorderTraversal(root);
    cout << endl;

    cout << "------------------------------------------------------------------\n";
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
