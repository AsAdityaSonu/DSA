#include<iostream>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int cost = 0;
        bool flag=1;

        while(flag){
            for(int i =0;i<tickets.size();i++){
                if(tickets[i]>0){
                    tickets[i]--;
                    cost++;
                }

                if(tickets[k]==0){
                    flag=0;
                    break;
                }

                if(tickets[i]==0){
                    if(i<k) k--;
                    tickets.erase(tickets.begin()+i);
                    i--;
                }
            }
        }
        return cost;
    }
};

int main()
{
    
    return 0;
}