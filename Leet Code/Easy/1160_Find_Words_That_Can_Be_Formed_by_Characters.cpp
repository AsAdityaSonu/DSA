#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mp;
        int ans=0;

        for(int i=0;i<chars.length();i++){
            mp[chars[i]]++;
        }

        for(auto word : words){
            unordered_map<char, int> wc;

            for(auto c : word){
                wc[c]++;
            }

            for(auto c : word){
                if(mp[c]<wc[c]){
                    goto alpha;
                }
            }
            ans+=word.length();
            alpha:
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}