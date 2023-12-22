#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n =digits.length();
        if(n==0){
            return{};
        }
        string mapp[]={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> s;

        for(auto a: mapp[digits[0]-'0']){
            s.push_back(string(1,a));
        }

        for(int i=1;i<n;i++){
            vector<string> s2;
            for(auto a: mapp[digits[i]-'0']){
                for(auto b:s){
                    s2.push_back(b+a);
                }
            }
            s=s2;
        }
        return s;
    }
};

int main()
{
    
    return 0;
}