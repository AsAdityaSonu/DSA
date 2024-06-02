#include<iostream>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.length()==0) return s;

        int open =0, close=0;
        string ans="";

        for(char c : s){
            if(c=='('){
                open++;
            }else if(c==')' && open>close){
                close++;
            }
        }

        int k=min(open, close);
        open=k;
        close=k;

        for(char c:s){
            if(c=='('){
                if(open>0){
                    ans+='(';
                    open--;
                }
                continue;
            }
            if(c==')'){
                if(close>0 && open<close){
                    ans+=')';
                    close--;
                }
                continue;
            }else{
                ans+=c;
            }
        }

        return ans;
    }
};

int main()
{
    
    return 0;
}