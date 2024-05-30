// GFG Link: https://practice.geeksforgeeks.org/problems/largest-element-in-array4009/1
#include<iostream>
using namespace std;

// C function to find maximum in arr[] of size n
int largest(int arr[], int n) {
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    
    return max;
}

int main()
{
    
    return 0;
}