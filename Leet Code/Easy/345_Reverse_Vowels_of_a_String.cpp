#include<iostream>
#include <stack>;
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> v;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'|| s[i]=='U'){
                v.push(s[i]);
            }
        }

        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'|| s[i]=='U'){
                s[i]=v.top();
                v.pop();
            }
        }

        return s;
    }
};

int main()
{
    
    return 0;
}