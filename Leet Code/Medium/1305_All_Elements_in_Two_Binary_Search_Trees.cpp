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
    void preOrder(TreeNode* root, vector<int> &v){
        if(root){
            v.push_back(root->val);
            preOrder(root->left, v);
            preOrder(root->right, v);
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        
        preOrder(root1,v);
        preOrder(root2,v);

        sort(v.begin(), v.end());

        return v;
    }
};

int main()
{
    
    return 0;
}