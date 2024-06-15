#include <iostream>
using namespace std;

// Approach 1
class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long mi = 0;
        for(int i = 0;i<N-1;i++)
        {   
            long long sum = 0;
            sum = arr[i]+arr[i+1];
            mi = max(sum,mi);
            // cout<< mi <<endl ;
            
        }
        return mi;
    }
};

int main()
{

    return 0;
}