#include<iostream>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> track(26,-1);
        int dis=-1;

        for(int i=0;i<s.length();i++){
            char c= s[i]-'a';
            if(track[c]!=-1){
                dis = max(dis, i- (track[c]+1));
            }
            
            if(track[c]==-1){
                track[c]=i;
            }
        }
        return dis;
    }
};

int main()
{
    
    return 0;
}