#include<iostream>
using namespace std;

// Approach 1: Better than 100% of submissions
class Solution {
public:
    int passThePillow(int n, int time) {
        int curr=1;

        while(curr<=time){
            for(int i=2;i<=n;i++){
                if(curr==time) return i;
                curr++;
            }

            for(int i=n-1;i>0;i--){
                if(curr==time) return i;
                curr++;
            }
        }

        return 0;
    }
};

// Approach 2
class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<=n-1){
            return time+1;
        }

        int Len = 2 * (n - 1);
        int movesLeft = time % Len;

        if (movesLeft < n) {
            return movesLeft+1;
        } else {
            return 2*n-movesLeft-1;
        }
    }
};

int main()
{
    
    return 0;
}