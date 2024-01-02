#include<iostream>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0 && n>0){
                flowerbed[i]=1;
                n--;
                if(i>0 && flowerbed[i-1]!=0){
                    flowerbed[i]=0;
                    n++;            
                } else if(i< flowerbed.size()-1 && flowerbed[i+1]!=0){
                    flowerbed[i]=0;
                    n++;
                }
            }
        }
        return n==0;
    }
};

int main()
{
    
    return 0;
}