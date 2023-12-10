// Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int bin(int arr[], int s, int ele) {
    int left = 0;
    int right = s - 1;

    while (left <= right) {
        int mid = (left +right) / 2;

        if (arr[mid] == ele) {
            return mid; //found
        } else if (arr[mid] < ele) {
            left = mid; //right half
        } else {
            right = mid; //the left half
        }
    }

    return -1; // not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ele = 11;

    cout<<size<<endl;
    int result = bin(arr, size, ele);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
