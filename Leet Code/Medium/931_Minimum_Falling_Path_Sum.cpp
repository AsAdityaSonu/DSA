#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                int min_val = matrix[i-1][j];

                if(j>0){
                    min_val= min(min_val, matrix[i-1][j-1]);
                }

                if(j<col-1){
                    min_val = min(min_val, matrix[i-1][j+1]);
                }

                matrix[i][j]+=min_val;
            }
        }

        return *min_element(matrix[row-1].begin(), matrix[row-1].end());
    }
};

int main()
{
    
    return 0;
}