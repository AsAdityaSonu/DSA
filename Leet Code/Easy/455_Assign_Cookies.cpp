#include<iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int num=s.size();
        if(num==0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m=0;
        int index = num-1;
        int ChildIndex = g.size()-1;

        while(index >=0 && ChildIndex>=0){
            if(s[index]>=g[ChildIndex]){
                m++;
                index--;
                ChildIndex--;
            }else{
                ChildIndex--;
            }
        }
        return m;
    }
};

int main()
{
    
    return 0;
}