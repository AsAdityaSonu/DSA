#include <iostream>

using namespace std;

bool is(int arr[], int l, int el) {
    for (int i = 0; i < l; ++i) {
        if (arr[i] == el) {
            return true;
        }
    }
    return false;
}

int count(int arr[], int length) {
    int C = 0;
    for (int i = 0; i < length; ++i) {
        if (!is(arr, i, arr[i])) {
            C++;
        }
    }
    return C;
}

int main() {
    int arr[] = {2, 4, 6, 2, 8, 4, 6, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int dis = count(arr, len);
    cout << "Total: " << dis << endl;

    return 0;
}
