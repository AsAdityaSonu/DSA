#include<iostream>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string s;
        if(str1+str2!=str2+str1) return s;

        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};

int main()
{
    
    return 0;
}