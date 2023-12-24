#include<iostream>
using namespace std;

// solution 1
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int m=word1.length();
        int n=word2.length();
        string s;
        while(i<m && i<n){
            s=s+word1[i];
            s=s+word2[i];
            i++;
        }
        while(i<m){
            s=s+word1[i];
            i++;
        }
        while(i<n){
            s=s+word2[i];
            i++;
        }
        return s;
    }
};

// solution 2
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int m=word1.length();
        int n=word2.length();
        string s;
        for (; i<m && i<n; ++i) {
            s+=word1[i];
            s+=word2[i];
        }
        while(i<m){
            s=s+word1[i];
            i++;
        }
        while(i<n){
            s=s+word2[i];
            i++;
        }
        return s;
    }
};

int main()
{
    
    return 0;
}