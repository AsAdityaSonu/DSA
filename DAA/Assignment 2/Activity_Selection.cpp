#include <iostream>
using namespace std;

void Activities(int s[], int f[], int n)
{
    int i, j;
    cout << "selected activities: ";
    i = 0;
    cout << i << " ";
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            cout << j << " ";
            i = j;
        }
    }
}

void act(int s[], int f[], int n)
{
    int curr = f[0];
    cout << "Acticities: ";
    cout << 0 << " ";

    for (int i = 1; i < n; i++)
    {
        if (s[i] >= curr)
        {
            cout << i << " ";
            curr = f[i];
        }
    }
}

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);

    Activities(s, f, n);
    cout << endl;
    act(s, f, n);
    return 0;
}