#include<iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char,int> ft;

        for(char c: t){
            ft[c]++;
        }

        int req = ft.size();
        int left =0,right =0;
        int formed =0;

        unordered_map<char, int> windowCount;
        int ans[3] = {-1,0,0};

        while(right<s.length()){
            char c= s[right];
            windowCount[c]++;

            if(ft.find(c) != ft.end() && windowCount[c] == ft[c]){
                formed++;
            }

            while(left<=right && formed == req){
                c=s[left];

                if(ans[0]==-1 || right-left+1<ans[0]){
                    ans[0]=right-left+1;
                    ans[1]=left;
                    ans[2]=right;
                }
                windowCount[c]--;
                if(ft.find(c) != ft.end() && windowCount[c] < ft[c]){
                    formed--;
                }
                left++;
            }
            right++;

        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};

int main()
{
    
    return 0;
}