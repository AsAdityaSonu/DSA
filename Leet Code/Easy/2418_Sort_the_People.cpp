#include<iostream>
#include<map> 
#include<vector>
#include<string>
using namespace std;

// Appraoch 01: Using map
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        map<int, string, greater<int>> mp;

        for(int i=0;i<n;i++){
            mp[heights[i]]=names[i];
        }

        int i=0;
        for(auto m:mp){
            names[i]=m.second;
            i++;
        }

        return names;
    }
};

int main()
{
    
    return 0;
}