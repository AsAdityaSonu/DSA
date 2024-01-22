#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
     int sumSubarrayMins(std::vector<int>& arr) {
        const int MOD=1e9 + 7;
        std::stack<int>stack;
        int result=0;

        for(int i=0;i<arr.size(); i++) {
            while(!stack.empty() && arr[i]<arr[stack.top()]) {
                int j=stack.top();
                stack.pop();
                int k=stack.empty()? -1:stack.top();
                result=(result+static_cast<long long>(arr[j]*(i - j)*(j - k)))%MOD;
            }

            stack.push(i);
        }

        while(!stack.empty()) {
            int j=stack.top();
            stack.pop();
            int k=stack.empty()?-1:stack.top();
            result=(result+static_cast<long long>(arr[j]*(arr.size()-j)*(j-k)))%MOD;
        }

        return result;
    }
};

int main()
{
    
    return 0;
}