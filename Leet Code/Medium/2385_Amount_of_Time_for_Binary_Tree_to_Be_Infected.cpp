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
    unordered_map<int, vector<int>> list;

    void convertToGraph(TreeNode* node){
        if(node){
            if(node->left){
                list[node->val].push_back(node->left->val);
                list[node->left->val].push_back(node->val); //Bidrectional
            }

            if(node->right){
                list[node->val].push_back(node->right->val);
                list[node->right->val].push_back(node->val); //Bidrectional
            }
            convertToGraph(node->left);
            convertToGraph(node->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        convertToGraph(root);

        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        int time =-1;

        while(!q.empty()){
            time++;
            int size=q.size();

            for(int i=0;i<size;i++){
                int curr = q.front();
                q.pop();
                visited.insert(curr);

                if (list.count(curr)) {
                    for (int neighbor : list[curr]) {
                        if (visited.find(neighbor) == visited.end()) {
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        return time;
    }
};

int main()
{
    
    return 0;
}