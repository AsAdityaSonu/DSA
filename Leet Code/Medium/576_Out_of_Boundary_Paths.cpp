#include<iostream>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int M = 1000000007;
        vector<vector<int>> v(m, vector<int>(n, 0));
        v[startRow][startColumn] = 1;
        int count = 0;

        for (int moves = 1; moves <= maxMove; moves++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1) count = (count + v[i][j]) % M;
                    if (j == n - 1) count = (count + v[i][j]) % M;
                    if (i == 0) count = (count + v[i][j]) % M;
                    if (j == 0) count = (count + v[i][j]) % M;

                    temp[i][j] = (
                        ((i > 0 ? v[i - 1][j] : 0) + (i < m - 1 ? v[i + 1][j] : 0)) % M +
                        ((j > 0 ? v[i][j - 1] : 0) + (j < n - 1 ? v[i][j + 1] : 0)) % M
                    ) % M;
                }
            }
            v = temp;
        }

        return count;
    }
};


int main()
{
    
    return 0;
}