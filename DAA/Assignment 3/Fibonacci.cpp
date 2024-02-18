#include <iostream>
using namespace std;

// iterative Method
void FibonacciItr(int n)
{
    int c;
    int i = 0;
    int j = 1;
    cout << i << " " << j << " ";
    while (j < n)
    {
        c = i + j;
        cout << c << " ";
        i = j;
        j = c;
    }
}

// Recursive method
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Recursive print
int FibonacciP(int n, int a = 0, int b = 1)
{
    if (n <= 0)
        return a;
    cout << a << " ";
    return FibonacciP(n - 1, b, a + b);
}

// fasterFibonacci
void fasterFibonacci(int n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    cout << a[0] << " " << a[1] << " ";
    for (int i = 2; i <= n; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
        cout << a[i] << " ";
    }
}

int main()
{
    FibonacciItr(5);
    cout << endl;

    for (int i = 0; i <= 5; ++i)
        cout << Fibonacci(i) << " ";
    cout << endl;

    FibonacciP(6); // n+1
    cout << endl;

    fasterFibonacci(5);
    return 0;
}