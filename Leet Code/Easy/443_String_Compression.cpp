#include<iostream>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1) return 1;
        
        string s;
        int c=0;
        int n = chars.size()-1;

        for(int i=1;i<chars.size();i++){
            if(i<chars.size() && chars[i]==chars[i-1]){
                c++;
            }else{
                s=s+chars[i-1];
                if(c>=1){
                    s=s+to_string(c+1);
                    c=0;
                }
            }
        }

        // Remaining part
        if(chars[n]==chars[n-1]){
            s=s+chars[n];
            s=s+to_string(c+1);
        }else{
            s=s+chars[n];
        }

        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }

        return s.size();
    }
};

int main()
{
    
    return 0;
}