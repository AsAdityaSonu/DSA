#include<iostream>
using namespace std;

// Apprach 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};

// Apprach 2
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        while(numBottles >= numExchange)
        {
            total += numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles%numExchange;
        }
        return total;
    }
};

int main()
{
    
    return 0;
}