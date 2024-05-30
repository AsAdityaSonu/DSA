// GFG Link: https://practice.geeksforgeeks.org/problems/second-largest/0
#include<iostream>
using namespace std;

//User function template for C++
class Solution{
public:	
	int print2largest(int arr[], int n) {
	    // code here
	    int max=arr[0];
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>max) max=arr[i];
	    }
	    
	    int second=-1;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>second && arr[i] !=max) second=arr[i];

	    }
	    
	    return second;
	}
};

int main()
{
    
    return 0;
}