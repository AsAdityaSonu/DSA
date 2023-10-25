#include <iostream>
using namespace std;

class TNode
{
public:
    TNode *left;
    int data;
    TNode *right;

    TNode(int val) : left(NULL), data(val), right(NULL)
    {
    }
};

bool isBST(TNode *root, int minVal = INT_MIN, int maxVal = INT_MAX)
{
    if (root == nullptr)
    {
        return 1;
    }

    if (root->data <= minVal || root->data >= maxVal)
    {
        return 0;
    }

    return isBST(root->left, minVal, root->data) && isBST(root->right, root->data, maxVal);
}

int main()
{
    TNode *root = new TNode(2);
    root->left = new TNode(1);
    root->right = new TNode(3);

    cout << isBST(root) << endl;

    return 0;
}