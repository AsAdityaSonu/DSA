// 1578. Minimum Time to Make Rope Colorful
#include<iostream>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=neededTime.size();
        int sum=0;
        for(int i=0;i<n-1;i++){
            if(colors[i]==colors[i+1]){
                if(neededTime[i+1]>neededTime[i]){
                    sum+=neededTime[i];
                }else{
                    sum+=neededTime[i+1];
                    swap(neededTime[i],neededTime[i+1]);
                }
            }
        }

        return sum;
    }
};

int main()
{
    
    return 0;
}