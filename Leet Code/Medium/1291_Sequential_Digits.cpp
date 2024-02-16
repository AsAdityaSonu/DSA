#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        
        for(int i=1;i<10;i++){
            int num=i;
            int next = i+1;

            while(num<=high && next<=9){
                num=num*10+next;
                if(low<=num && num<=high){
                    v.push_back(num);
                }
                next++;
            }
        }

        sort(v.begin(),v.end());

        return v;
    }
};

int main()
{
    
    return 0;
}