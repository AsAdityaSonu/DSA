#include<iostream>
#include<vector>
using namespace std;

// Appraoch 1: Transpose and then exchange columns/reverse rows
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        int mid = n/2;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<mid; ++j) {
                swap(matrix[i][j],matrix[i][matrix.size()-1-j]);
            }
        }
    }
};

// Approach 2: using another matrix
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

int main()
{
    
    return 0;
}