#include<iostream>
using namespace std;

int main()
{
    int a[] = {6, 7, 2, 3, 5};
    int n = 5;

    for(int i = 1; i < n; i++) {
        int pivot = a[i];
        int j = i - 1;
        while(j >= 0 && pivot < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = pivot;
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
