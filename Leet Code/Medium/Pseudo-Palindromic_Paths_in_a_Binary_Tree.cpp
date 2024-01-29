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
    int pseudoPalindromicPaths (TreeNode* root) {
        int count =0;
        int path =0;

        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});

        while(!s.empty()){
            auto [node, path] = s.top();
            s.pop();

            if (node != nullptr){
                path =path ^ (1 << node-> val);

                
                if(node->left == nullptr && node->right == nullptr){
                    if((path & (path-1))==0){
                        count++;
                    }
                }else{
                    s.push({node->right, path});
                    s.push({node->left, path});
                }
            }
        }
        return count;
    }
};

int main()
{
    
    return 0;
}