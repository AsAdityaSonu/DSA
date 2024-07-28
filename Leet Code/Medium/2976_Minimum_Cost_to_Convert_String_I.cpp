#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> ans(26, vector<long long>(26, LONG_MAX));

        for(int i=0;i<26;i++){
            ans[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            ans[original[i]-'a'][changed[i]-'a']=min(ans[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }

        for(int k=0;k<26;k++){
            for (int i = 0; i <26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (ans[i][k] < LONG_MAX && ans[k][j] < LONG_MAX) {
                        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                int srcChar = source[i] - 'a';
                int tgtChar = target[i] - 'a';
                if (ans[srcChar][tgtChar] == LONG_MAX) {
                    return -1; 
                }
                totalCost += ans[srcChar][tgtChar];
            }
        }
        return totalCost < LONG_MAX ? totalCost : -1;
    }
};

int main()
{
    
    return 0;
}