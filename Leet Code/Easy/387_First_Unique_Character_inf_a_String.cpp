#include<iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        vector<int> v(26,0);

        for(auto c: s) v[c-'a']++;

        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==1){
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    
    return 0;
}