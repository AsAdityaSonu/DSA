#include<iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<int> &v){
        if(root){
            if(root->left==NULL && root->right==NULL){
                v.push_back(root->val);
            }
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;

        preorder(root1, v1);
        preorder(root2, v2);

        return v1==v2;
    }
};

int main()
{
    
    return 0;
}