#include <iostream>

using namespace std;

struct TNode
{
    TNode *left;
    int data;
    TNode *right;

    TNode(int val) : left(NULL), data(val), right(NULL){}
};

class bst
{
    TNode *root;

    TNode *insert(TNode *node, int val)
    {
        if (node == NULL)
        {
            return new TNode(val);
        }

        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        return node;
    }

    TNode *findMin(TNode *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    TNode *remove(TNode *node, int val)
    {
        if (node == NULL)
        {
            return node;
        }

        if (val < node->data)
        {
            node->left = remove(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = remove(node->right, val);
        }
        else
        {
            if (node->left == NULL)
            {
                TNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                TNode *temp = node->left;
                delete node;
                return temp;
            }
            TNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    int maxDepth(TNode *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return 1 + max(leftDepth, rightDepth);
        cout<<"hello";
        cout<<"-------------------";
    }

    int minDepth(TNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (leftDepth == 0)
        {
            return 1 + rightDepth;
        }
        else if (rightDepth == 0)
        {
            return 1 + rightDepth;
        }
        else
        {
            return 1 + min(leftDepth, rightDepth);
        }
    }

public:
    bst() : root(NULL) // Member init.
    {
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void remove(int val)
    {
        root = remove(root, val);
    }

    int maxDepth()
    {
        return maxDepth(root);
    }

    int minDepth()
    {
        return minDepth(root);
    }
};

int main()
{
    bst bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    // cout << "Reached 1" << endl;

    cout << bst.maxDepth() << endl;
    // cout << "Reached 2" << endl;

    cout << bst.minDepth() << endl;
    // cout << "Reached 3" << endl;

    bst.remove(30);
    // cout << "Reached 4" << endl;

    cout << bst.maxDepth() << endl;
    // cout << "Reached 5" << endl;

    cout << bst.minDepth() << endl;
    // cout << "Reached 6" << endl;
}