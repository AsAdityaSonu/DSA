#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Approach 1
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int a1 = edges[0][1];

        int b= edges[1][0];
        int b1 = edges[1][1];

        if( a== b || a==b1) return a;


        if( a1==b || a1 == b1) return a1;
        
        return -1;
    }
};

// Approach 2
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;

        for(auto a: edges){
            mp[a[0]]++;
            mp[a[1]]++;
        }

        int n= mp.size();
        for(auto a: mp){
            if(a.second==n-1){
                return a.first;
            }
        }

        return -1;
    }
};

int main()
{
    return 0;
}