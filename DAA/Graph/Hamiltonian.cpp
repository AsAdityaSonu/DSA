#include <iostream>
using namespace std;
int n, G[10][10], x[10];

void NextValue(int k)
{
    int j;
    while (true)
    {
        x[k] = (x[k] + 1) % (n + 1);

        if (x[k] == 0)
            return;
        if (G[x[k - 1]][x[k]] != 0)
        {
            for (j = 1; j <= k - 1; j++)
            {
                if (x[j] == x[k])
                    break;
            }
            if (j == k)
            {
                if (k < n || (k == n && G[x[n]][x[1]] != 0))
                {
                    return;
                }
            }
        }
    }
}

void Hamiltonian(int k)
{
    while (true)
    {
        NextValue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            for (int i = 1; 1 <= n; i++)
            {
                cout << x[i] << "\t";
            }
        }
        else
        {
            Hamiltonian(k + 1);
        }
    }
}

int main()
{
    // int n;
    cout << "enter the number of vertices of the graph";
    cin >> n;
    // int G[n][n];
    cout << "enter the adjency matrices";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    // x[1]=1;
    Hamiltonian(1);
    return 0;
}