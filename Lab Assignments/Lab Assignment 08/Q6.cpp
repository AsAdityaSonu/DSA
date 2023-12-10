#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    if (start > end)
        return NULL;

    int curr = preorder[start];
    Node *node = new Node(curr);

    int pos;
    for (pos = start; pos <= end; pos++)
    {
        if (inorder[pos] == curr)
        {
            break;
        }
    }

    node->left = buildTree(preorder, inorder, start + 1, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}


int main()
{

    vector<int> preorder = {1, 2, 4, 5, 3, 6};
    vector<int> inorder = {4, 2, 5, 1, 6, 3};

    Node *root = buildTree(preorder, inorder, 0, preorder.size() - 1);

    return 0;
}
