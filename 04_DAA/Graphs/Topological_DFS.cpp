#include <iostream>
using namespace std;
int s[100], j, res[100], a[10][10];
void dfs(int u, int n)

{
    int v;
    s[u] = 1;
    for (v = 0; v < n - 1; v++)
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
    int i, u;
    for (i = 0; i < n; i++)
    {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++)
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
    int a[100][100], n, i, j;

    cout << "Enter number of vertices\n";
    cin >> n;

    cout << "\t\tAdjacency Matrix of the graph\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    printf("\nTopological order:\n");
    topological_order(n);

    for (i = n; i >= 1; i--)
    {
        cout << "-->" << res[i];
    }
    return 0;
}