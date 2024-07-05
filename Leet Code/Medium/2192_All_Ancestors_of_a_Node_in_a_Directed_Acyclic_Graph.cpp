#include<iostream>
#include<vector>
using namespace std;

// Approach: DFS
class Solution {
private:
    void dfs(vector<vector<int>>& adj, int parent, int curr, vector<vector<int>>& res, vector<bool>& visit){
        visit[curr]=true;
        for(int dest: adj[curr]){
            if(!visit[dest]){
                res[dest].push_back(parent);
                dfs(adj, parent, dest, res, visit);
            }
        }
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector< vector<int> > adj(n);
        vector< vector<int> > ans(n);

        for(auto a: edges){
            adj[a[0]].push_back(a[1]);
        }

        for(int i=0;i<n;i++){
            vector<bool> visit(n, false);
            dfs(adj, i, i, ans, visit);
        }

        for(int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}