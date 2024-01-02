#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string str;

        int i=s.length()-1;
        while(i>=0){
            if(s[i]==' '){
                i--;
                continue;
            }
            string temp;
            while(i >= 0 && s[i]!=' '){
                temp+=s[i];
                i--;
            }
            reverse(temp.begin(),temp.end());
            str=(!str.empty() ? str + ' ' : "")+temp;
        }
        return str;
    }
};

int main()
{
    
    return 0;
}