#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printLCP(vector<vector<int> > &dp, string s1, string s2, int i, int j, string & result){
    if (i==0 || j==0) return;

    if(s1[i-1]==s2[j-1]){
        printLCP(dp, s1, s2, i-1, j-1, result);
        result.push_back(s1[i-1]);
    }else{
        if(dp[i][j-1]>dp[i-1][j]){
            printLCP(dp, s1, s2, i, j-1, result);
        }else{
            printLCP(dp, s1, s2, i-1, j, result);
        }
    }
}

void LCP(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<"Length of Longest Palindromic Subsequence: "<<dp[m][n]<<endl;
    string result;

    printLCP(dp, s1, s2, m,n, result);
    cout<<result;
}

int main(){
    string str1 = "ABCDAB";
    string str2 = "BADCBA";
    LCP(str1, str2);
    return 0;
}