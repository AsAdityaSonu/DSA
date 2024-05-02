#include<iostream>
#include<climits>
using namespace std;

int sum(int freq[], int i, int j);

int optimalSearchTree(int keys[], int freq[], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++)
     dp[i][i] = freq[i];

    for (int L=2; L<=n; L++) {
        for (int i=0; i<=n-L+1; i++) {
            int j = i+L-1;
         dp[i][j] = INT_MAX;

            for (int k=i; k<=j; k++) {
                int q = ((k > i)? dp[i][k-1]:0) + 
                        ((k < j)? dp[k+1][j]:0) + 
                        sum(freq, i, j);
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[0][n-1];
}

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys)/sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
    return 0;
}