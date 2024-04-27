#include <iostream>
using namespace std;
int s[100], j=0, res[100], a[10][10];

void dfs(int u, int n)
{
    s[u] = 1;
    for (int v = 0; v < n - 1; v++)
    {
        if (a[u][v] == 1 && s[v] == 0)
        {
            dfs(v, n);
        }
    }
    j += 1;
    res[j] = u;
}

void topological_order(int n)
{
    for (int u = 0; u < n; u++)
    {
        if (s[u] == 0)
        {
            dfs(u, n);
        }
    }
    return;
}

int main()
{
    int a[100][100], n;

    cout << "Enter number of vertices\n";
    cin >> n;

    cout << "\t\tAdjacency Matrix of the graph\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }

    printf("\nTopological order:\n");
    topological_order(n);

    for (int i = n; i >= 1; i--)
    {
        cout << "-->" << res[i];
    }
    return 0;
}