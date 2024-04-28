#include<iostream>
using namespace std;

const int MAX = 100;

int matrixChainMultiplication(int p[], int n) {
    int m[MAX][MAX];

    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for(int L=2;L<=n;L++){
        for(int i=1;i<=n-L+1;i++){
            int j=L+i-1;
            m[i][j]= INT_MAX ;

            for(int k= i;k<=j-1;k++){
                int q= m[i][k]+m[k+1][j] +p[i-1]*p[j]*p[k];
                if(q<m[i][j]) m[i][j]=q;
            }
        }
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return m[1][n];
}

int main()
{
    int arr[] = {5,4,6,2,7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is: " << matrixChainMultiplication(arr, n - 1) << endl;

    return 0;
}