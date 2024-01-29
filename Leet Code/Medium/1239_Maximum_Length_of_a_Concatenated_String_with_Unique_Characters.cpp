#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool valid(const string& curr, const string& str){
        unordered_set<char> charSet;

        for(char ch: str){
            if(charSet.count(ch)>0){
                return 0;
            }

            charSet.insert(ch);

            if (curr.find(ch)!= string::npos) {
                return 0;  
            }
        }
        return 1;
    }

    void backtrack(vector<string> &arr, string current, int start, int& len){
        if(len < current.length()) len =current.length();

        for(int i = start; i<arr.size();i++){
            if(!valid(current, arr[i])){
                continue;
            }

            backtrack(arr, current+arr[i], i+1, len);
        }
    }

    int maxLength(vector<string>& arr) {
        int result =0;
        backtrack(arr, "",0,result);
        return result;
    }
};

int main()
{
    
    return 0;
}