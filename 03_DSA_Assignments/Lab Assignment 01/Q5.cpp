#include<iostream>
using namespace std;

int main(){
    int n;
    int a[3][3];
    int temp;

    cout << "Enter the order of matrix: ";
    cin >> n;

    // INPUT
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

    int sum[n];
    // for rows
    for (int i=0; i<n; i++){
        sum[i]=0;
        for(int j=0; j<n; j++){
            sum[i]+=a[i][j];
        }
    }

    int sum1[n];
    // for rows
    for (int i=0; i<n; i++){
        sum1[i]=0;
        for(int j=0; j<n; j++){
            sum1[i]+=a[j][i];
        }
    }
    
    cout<<"-------------------------------------------\n";
    // Printing the matrix
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-------------------------------------------\n";

    // Printing the sum of rows
    for(int i=0; i<n; i++){
        cout<<"Sum of "<<i<<" row is "<<sum[i]<<endl;
    }

    // Printing the sum of columns
    for(int i=0; i<n; i++){
        cout<<"Sum of "<<i<<" column is "<<sum1[i]<<endl;
    }

    return 0;
}