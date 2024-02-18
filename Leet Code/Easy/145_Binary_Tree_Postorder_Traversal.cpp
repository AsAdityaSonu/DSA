#include<iostream>
#include<stack>
#include<vector>
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

// solution 1
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(!root) return ans;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left != nullptr){
                s1.push(curr->left);
            }
            if(curr->right != nullptr){
                s1.push(curr->right);
            }
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;
    }
};

// solution 2
class Solution {
public:
    void POT(TreeNode* root,vector<int> &v){
        if(root){
            POT(root->left, v);
            POT(root->right, v);
            v.push_back(root->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        POT(root, v);

        return v;
    }
};

int main()
{
    
    return 0;
}