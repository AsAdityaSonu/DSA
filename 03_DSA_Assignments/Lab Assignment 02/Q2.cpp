// Bubble Sort
// 64   34  25  12  22  11  90
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 90, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int temp;

    // Sorting
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
            }
        }
    }

    for (int i = (sizeof(arr) / sizeof(arr[0])) - 1; i >= 0; i--)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}