#include <iostream>
#include <cstdlib>
using namespace std;
void NQueen(int, int);
bool place(int, int);
int x[10];
int count = 0;
void NQueen(int j, int n)
{
    for (int k = 1; k <= n; k++)
    {
        if (place(j, k))
        {
            x[j] = k;
            if (j == n)
            {
                ::count++;
                cout << endl;
                for (int j1 = 1; j1 <= n; j1++)
                {
                    cout << x[j1] << "\t";
                }
            }
            else
            {
                NQueen(j + 1, n);
            }
        }
    }
}
bool place(int j, int k)
{
    for (int i = 1; i <= j - 1; i++)
    {
        if ((x[i] == k) || (abs(x[i] - k) == abs(i - j)))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "enter the number of queen" << endl;
    cin >> n;
    int k = 1;
    NQueen(k, n);
    cout << endl
         << "count=\t" << ::count;
    return 0;
}