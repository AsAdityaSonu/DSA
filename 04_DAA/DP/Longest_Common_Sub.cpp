#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printLCS(vector<vector<int> > &dp, string s1, string s2, int i, int j, string &result)
{
    if (i == 0 || j == 0)
        return;
    if(s1[i-1]==s2[j-1]){
        printLCS(dp, s1, s2, i-1, j-1,result);
        result.push_back(s1[i-1]);
    }else{
        if(dp[i-1][j]>dp[i][j-1]){
            printLCS(dp, s1, s2, i-1, j,result);
        }else{
            printLCS(dp, s1, s2, i, j-1,result);
        }
    }
}

void LCS(string s1, string s2){
    int m = s1.length();
    int n = s2.length();

    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<"Length of LCS: "<<dp[m][n]<<endl;
    string result;
    printLCS(dp, s1, s2, m ,n, result);
    cout<<"LCS: "<<result<<endl;
}

int main()
{
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    LCS(str1, str2);
    return 0;
}