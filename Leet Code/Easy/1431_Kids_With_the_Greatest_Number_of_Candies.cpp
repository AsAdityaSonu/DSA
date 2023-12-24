#include<iostream>
using namespace std;

// solution 1 (Better one with 0 time complexity)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;

        if (candies.empty()) {
            return v;    
        }


        int m=candies[0];
        for(int i =1;i<candies.size();i++){
            if(m<candies[i]){
                m= candies[i];
            }
        }

        for(int i=0;i<candies.size();i++){
            if((extraCandies+candies[i])<m){
                v.push_back(0);
            }else{
                v.push_back(1);
            }
        }

        return v;
    }
};

// solution 2
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> v;

        if (candies.empty()) {
            return v;    
        }

        int maxCandies = candies[0];
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }

        for (int candy : candies) {
            v.push_back(extraCandies + candy >= maxCandies);
        }

        return v;

        return v;
    }
};

int main()
{
    
    return 0;
}