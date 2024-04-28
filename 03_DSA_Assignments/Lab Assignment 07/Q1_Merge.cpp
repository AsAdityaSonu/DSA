#include <iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int b[10];
    int i = lb;
    int j = mid + 1;
    int k = lb;

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x];
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;

        // Sort the first and second halves
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);

        // Merge 
        merge(arr, lb, mid, ub);
    }
}

int main() {
    int arr[] = {6, 7, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
