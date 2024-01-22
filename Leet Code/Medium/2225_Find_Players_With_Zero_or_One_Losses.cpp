#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> zero;
        vector<int> one;
        unordered_map<int,int> mp;

        for(int i=0;i<matches.size();i++){
            int win = matches[i][0];
            mp[win]=0;
        }

        for(int i=0;i<matches.size();i++){
            int lose =  matches[i][1];
            mp[lose]++;
        }

        for(auto it = mp.begin(); it!=mp.end();it++){
            int key = it->first;
            int value = it->second;

            if(value==0){
                zero.push_back(key);
            }else if(value==1){
                one.push_back(key);
            }
        }

        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());

        return {zero, one};
    }
};

int main()
{
    
    return 0;
}