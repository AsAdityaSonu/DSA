#include<iostream>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(auto c: arr) mp[c]++;

        vector<int> fr;

        for(auto p :mp){
            fr.push_back(p.second);
        }

        sort(fr.begin(), fr.end());
        // sort(begin(fr), end(fr));

        int count=0;
        for(int a:fr){
            if(k>=a){
                k-=a;
                count++;
            }else{
                break;
            }
        }

        return fr.size()-count;
        
    }
};

int main()
{
    
    return 0;
}