#include <iostream>
using namespace std;

// Recursion
bool Binary(int arr[], int p, int q, int target)
{
    if (p <= q)
    {
        int mid = p + (q - p) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            return Binary(arr, mid + 1, q, target);
        else
        {
            return Binary(arr, p, mid - 1, target);
        }
    }
    return false;
}

// Iter
bool BinaryIter(int arr[], int p, int q, int target)
{
    while (p < q)
    {
        int mid = p + (q - p) / 2;

        if (arr[mid] == target)
        {
            return 1;
        }
        if (arr[mid] < target)
        {
            p = mid + 1;
        }
        else
        {
            q = mid - 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {10, 15, 18, 20, 21, 24, 26, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;

    // Recursion
    if (Binary(arr, 0, n - 1, target))
    {
        cout << "FOund" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // Iter
    if (BinaryIter(arr, 0, n - 1, target))
    {
        cout << "FOund" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    // return 0;
}