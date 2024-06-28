#include<iostream>
#include<vector>
using namespace std;

// Approach 1: Inorder Traversal + Construct BST
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
    void inTraverse(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        inTraverse(root->left, inorder);
        inorder.push_back(root->val);
        inTraverse(root->right, inorder);
    }

    TreeNode* construct(vector<int>& in, int low, int high){
        if(low>high) return NULL;

        int mid = low + (high-low)/2;
        TreeNode* curr = new TreeNode(in[mid]);
        curr -> left = construct(in, low, mid-1);
        curr->right =  construct(in, mid+1, high);
        return curr;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return NULL;
        vector<int> inorder;
        inTraverse(root, inorder);

        return construct(inorder, 0, inorder.size()-1);
    }
};

int main()
{
    
    return 0;
}