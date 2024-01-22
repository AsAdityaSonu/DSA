#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        size_t row=bank.size();
        size_t col=bank[0].size();
        int c=0;

        for(int i=0;i<row-1;i++){
            for(int j=0;j<col;j++){
                if(bank[i][j]=='1'){
                    int increment =i+1;
                    int temp=0;
                    while(temp==0 && increment<row){
                        temp = count(bank[increment].begin(), bank[increment].end(), '1');
                        increment++;
                    }
                    c+=temp;
                }
            }
        }
        
        return c;
    }
};

int main()
{
    
    return 0;
}