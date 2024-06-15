#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// Approach 1 : Priority Queue
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> v;
        int n= profits.size();

        for(int i=0;i<n;i++){
            v.push_back({capital[i], profits[i]});
        }

        sort(v.begin(), v.end());

        priority_queue<int> maxHeap;
        int i=0;

        while(k>0){
            while(i<n && v[i].first <=w){
                maxHeap.push(v[i].second);
                ++i;
            }

            if(maxHeap.empty()) break;

            w+=maxHeap.top();
            maxHeap.pop();
            --k;
        }
        return w;
    }
};

int main()
{
    
    return 0;
}