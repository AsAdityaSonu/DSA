#include <iostream>
using namespace std;

int main()
{
    int alloc[][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max[][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

    int need[5][3];

    // need matrix
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int avail[3] = {3, 3, 2};
    int n = 5;
    int r = 3;
    int completed = 0;
    int compP[5] = {0};

    int i = 0;
    while (completed != n)
    {
        if (compP[i] == 1)
        {
            i = (i + 1) % n;
            continue;
        }

        bool flag = 1;
        for (int a = 0; a < r; a++)
        {
            if (need[i][a] > avail[a])
            {
                flag = 0;
            }
        }

        if (flag)
        {
            for (int a = 0; a < r; a++)
            {
                avail[a] += alloc[i][a];
            }
            compP[i] = 1;
            completed++;
            cout << "Process P" << i << " exexuted" << endl;
        }
        i = (i + 1) % n;
    }

    return 0;
}
