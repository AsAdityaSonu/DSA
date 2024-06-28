#include<iostream>
#include<vector>
using namespace std;

// Approach 1
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;
        int n=difficulty.size();
        for (int i=0; i<n;i++) {
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());

        int p=0;
        int j=0;
        int result=0;
        for(int a:worker) {
            while(j<n && a>=v[j].first) {
                p=max(p,v[j].second);
                ++j;
            }
            result += p;
        }
        return result;
    }
};

// Approach 2
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int> > v;
        int n=difficulty.size();
        int c=0;

        for(int i=0;i<n;i++){
            v.push_back({profit[i], difficulty[i]});
        }

        sort(v.rbegin(), v.rend());

        int m= worker.size();
        for (int i=0;i<m;i++) {
            for (auto a:v) {
                if(worker[i]>=a.second) {
                    c+=a.first;
                    break;
                }
            }
        }

        return c;
    }
};



int main()
{
    
    return 0;
}