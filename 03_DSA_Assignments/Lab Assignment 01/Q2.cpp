// Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should contain the unique elements.

#include <iostream>
using namespace std;

void rem(int arr[], int &size) {
    int newS = 0;

    for (int i = 0; i < size; i++) {
        bool isDup = false;

        for (int j = 0; j < newS; j++) {
            if (arr[i] == arr[j]) {
                isDup = true;
                break;
            }
        }

        if (!isDup) {
            arr[newS] = arr[i];
            newS++;
        }
    }

    size = newS;
}

int main() {
    int Arr[] = {1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(Arr) / sizeof(Arr[0]);

    rem(Arr, size);

    cout << "Unique elements: ";
    for (int i = 0; i < size; i++) {
        cout << Arr[i] << " ";
    }

    return 0;
}
