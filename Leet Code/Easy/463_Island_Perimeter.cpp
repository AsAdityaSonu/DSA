#include<iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0) ans++;
                    if(j==0) ans++;

                    if(i>0 && grid[i-1][j]==0) ans++;
                    if(i<m-1 && grid[i+1][j]==0) ans++;

                    if(j>0 && grid[i][j-1]==0) ans++;
                    if(j<n-1 && grid[i][j+1]==0) ans++;

                    if(i==m-1) ans++;
                    if(j==n-1) ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    
    return 0;
}