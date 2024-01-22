#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

// Solution 01
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;

        for(int i=0;i<arr.size();i++){
            int current = arr[i];
            mp[current]++;
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            int key1=it->first;
            int val1=it->second;
            for(auto iit=mp.begin();iit!=mp.end();iit++){
                int key2 = iit->first;
                int val2 = iit->second;
                if(key1!=key2 && val1==val2){
                    return 0;
                }
            }
        }

        return 1;
    }
};

// Solution 02
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;

        for(auto i: arr) mp[i]++;
        for(auto i: mp) st.insert(i.second);

        return st.size() == mp.size();
    }
};

int main()
{
    
    return 0;
}