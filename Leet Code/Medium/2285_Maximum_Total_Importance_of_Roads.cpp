#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// Approach 1: Using Formula
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);

        for(auto& e: roads){
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        sort(deg.begin(), deg.end());
        
        long long ans=0;
        for(int i=0; i<n; i++)
            ans+=(i+1LL)*deg[i];
        return ans;
    }
};

// Approach: Using Sorting
class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int, int> v;
        for(auto road: roads){
            v[road[0]]++;
            v[road[1]]++;
        }

        vector<pair<int, int>> vec(v.begin(), v.end());
        sort(vec.begin(), vec.end(), comp);

        for(auto a: vec){
            cout<<a.first<<" "<<a.second<<" "<<endl;
        }

        // wt
        vector<int> wt(n,0);
        int val=n;
        for(auto& a: vec){
            wt[a.first]=val;
            val--;
        }

        long long imp= 0;
        for(int i=0;i<roads.size();i++){
            imp+=wt[roads[i][0]]+wt[roads[i][1]];
        }

        return imp;
    }
};

int main()
{
    
    return 0;
}