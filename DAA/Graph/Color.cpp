#include <iostream>
using namespace std;
#define ROW 10
// const int m=3;
int g[ROW][ROW], x[ROW];
bool isSafe(int k, int c, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (g[k][i] == 1 && c == x[i])
        {
            return false;
        }
    }
    return true;
}

void graph_color(int k, int m, int n)
{

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(k, c, n))
        {
            x[k] = c;
            if ((k + 1) < n)
            {
                graph_color(k + 1, m, n);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << x[i];
                }
                cout << endl;
                return;
            }
        }
    }
}

int main()
{ // int k;
    int n, m;
    cout << "enter the number of vertices";
    cin >> n;
    cout << "enter the no. of colors";
    cin >> m;
    cout << "enter the adjacency matrix";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    graph_color(0, m, n);

    return 0;
}