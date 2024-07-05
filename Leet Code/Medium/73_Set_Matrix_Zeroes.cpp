#include<iostream>
#include<vector>
using namespace std;

// Approach 1: Not for -ve Numbers (still solved using INT_MIN-9*5+1) ---- NOT SUGGESTED ----
class Solution {
private:
    void markZeroes(vector<vector<int>>& matrix, int row, int col, int m, int n) {
        for (int i = 0; i < n; ++i) {
            if (matrix[row][i] != 0) {
                matrix[row][i] = INT_MAX-9*5+1; 
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (matrix[i][col] != 0) {
                matrix[i][col] = INT_MAX-9*5+1;
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]==0) {
                    markZeroes(matrix, i, j, m ,n);
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (matrix[i][j]== INT_MAX-9*5+1) {
                    matrix[i][j]=0;
                }
            }
        }
    }
};

// Approach 2: Using 1st row and 1st column as markers
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> row(m, 0); 
        vector<int> col(n, 0); 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Approach 3: Using 1st row and 1st column as markers (Optimized)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int col0=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // Row
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                // Col
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main()
{
    
    return 0;
}