#include <iostream>
#include <cstdlib>
using namespace std;

int partition(int a[], int lb, int ub) {
    int pivot = a[lb]; 
    int start = lb;
    int end = ub;

    while (start < end) {
        while (a[start] <= pivot) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(a[start], a[end]);
        }
    }

    swap(a[lb], a[end]);

    return end;
}

void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pivotIndex = partition(a, lb, ub);
        quickSort(a, lb, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, ub);
    }
}

int main() {
    int a[] = {6, 7, 2, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}