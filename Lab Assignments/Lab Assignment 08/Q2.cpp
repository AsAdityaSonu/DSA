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

int MinEle(TNode *root){
    if(root == nullptr){
        return INT_MAX;
    }

    int leftMin = MinEle(root->left);
    int rightMin = MinEle(root->right);

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
    int key2 = 40;
    TNode *found2 = searchItr(root, key2);
    if (found2)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // Max Ele..
    int max = MaxEle(root);
    cout << "max ele is: " << max << endl;

    // Min Ele..
    int min = MinEle(root);
    cout<<"min ele is: "<< min<<endl;

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
