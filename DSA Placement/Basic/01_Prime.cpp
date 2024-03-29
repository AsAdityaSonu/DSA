#include <iostream>
using namespace std;

void prime(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not Prime";
            break;
        }
    }
    if (i == n)
    {
        cout << "Prime";
    }
}

int main()
{
    int n;
    cin >> n;
    prime(n);

    return 0;
}