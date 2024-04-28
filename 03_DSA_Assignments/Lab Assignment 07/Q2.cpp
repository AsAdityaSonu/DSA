#include<iostream>
using namespace std;

void bidirectionalSelectionSort(int a[], int n) {
    int left = 0;      
    int right = n - 1;  

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) {
                minIndex = i; 
            }
            if (a[i] > a[maxIndex]) {
                maxIndex = i; 
            }
        }

        if (minIndex == right && maxIndex == left) {
            swap(a[left], a[right]);
        } else {

            swap(a[left], a[minIndex]);
            swap(a[right], a[maxIndex]);
        }

        left++;  
        right--;
    }
}

int main() {
    int a[] = {6, 7, 2, 3, 5};
    int n = 5;

    bidirectionalSelectionSort(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl; 
    }
    return 0;
}
