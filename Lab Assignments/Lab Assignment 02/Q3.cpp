// Logic to find missing numbers in sorted array

#include <iostream>
using namespace std;

void Miss(int arr[], int size, int s, int end) {
    int curr = s;
    
    for (int i = 0; i < size; i++) {
        int ele = arr[i];
        while (curr < ele) {
            cout << curr << " ";
            curr++;
        }
        curr = ele + 1;
    }
    
    while (curr <= end) {
        cout << curr << " ";
        curr++;
    }
}

int main() {
    int arr[] = {2, 4, 7, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = arr[0];
    int end = arr[size - 1];
    
    cout << "Missing numbers: ";
    Miss(arr, size, start, end);
    
    return 0;
}
