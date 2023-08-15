// Implement the Binary search algorithm regarded as a fast search algorithm with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <iostream>
using namespace std;

int bin(int arr[], int s, int t) {
    int left = 0;
    int right = s - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == t) {
            return mid; // Element found
        } else if (arr[mid] < t) {
            left = mid + 1; //right half
        } else {
            right = mid - 1; //the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int t = 11;

    int result = bin(arr, size, t);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
