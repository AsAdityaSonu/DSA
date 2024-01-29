#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isMirror(TreeNode* node1, TreeNode* node2){
        if(node1==NULL && node2==NULL) return 1;
        if(node1==NULL || node2==NULL) return 0;

        return node1->val == node2->val && isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return 1;
        }

        return isMirror(root->left, root->right);
    }
};

int main()
{
    
    return 0;
}