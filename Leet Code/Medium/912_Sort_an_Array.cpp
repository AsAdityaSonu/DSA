#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> LeftArray(n1);
        vector<int> RightArray(n2);
        
        for (int i = 0; i < n1; i++)
            LeftArray[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            RightArray[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (LeftArray[i] <= RightArray[j]) {
                arr[k] = LeftArray[i];
                i++;
            } else {
                arr[k] = RightArray[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = LeftArray[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = RightArray[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if(left<right){
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};

int main()
{
    
    return 0;
}