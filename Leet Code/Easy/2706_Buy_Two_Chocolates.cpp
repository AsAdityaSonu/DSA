#include<iostream>
using namespace std;

// Solution 1
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int m = money;
        int count=0;

        //sorting array
        for(int i=0;i<prices.size()-1;i++){
            for(int j=0;j<prices.size()-i-1;j++){
                if(prices[j+1]<prices[j]){
                    swap(prices[j+1],prices[j]);
                }
            }
        }

        for(int i =0;i<prices.size();i++){
            if(prices[i]<=money && count<2){
                money-=prices[i];
                count++;
            }
        }
        if(count ==2){
            cout<<"you can buy!!!";
            return money;
        }else{
            return m;
        }
        
    }
};

// Solution 2
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size() < 2){
            return money;
        }
        //FIND MIN
        int min=prices[0], min2=INT_MAX;
        int index=NULL;
        for(int i=0;i < prices.size();i++){
            if(prices[i]<min){
                min2=min; 
                min=prices[i];
                index=i;
            }
        }
        for(int i =0;i<prices.size();i++){
            if(min2>prices[i] && i!=index){
                min2=prices[i];
            }
        }
    
        if(min+min2<=money){
            money-=min;
            money-=min2;
            return money;
        }else{
            return money;
        }
        
    }
};

int main()
{
    
    return 0;
}