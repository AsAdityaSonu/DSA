#include<iostream>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int max=INT_MIN;
        for(int i=1;i<s.length();i++){
            int zeros=0, ones=0;
            for(int j=0;j<i;j++){
                if(s[j]=='0'){
                    zeros++;
                }
            }
            for(int k=i;k<s.length();k++){
                if(s[k]=='1'){
                    ones++;
                }
            }
            if(zeros+ones>=max){
                max= zeros+ones;
            }
        }
        return max;
    }
};

int main()
{
    
    return 0;
}