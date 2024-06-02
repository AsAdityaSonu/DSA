#include<iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        int count=0,m=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            m=max(count,m);
            if(s[i]==')') count--;
        }
        return m;
    }
};

int main()
{
    
    return 0;
}