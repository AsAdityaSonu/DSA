#include<iostream>
using namespace std;

int main()
{   int n;
    int a[3][3];
    int temp;

    cout << "Enter the order of matrix: ";
    cin >> n;

    // INPUT
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // cin >> a[i][j];
            a[i][j]=i+j+i+i+i+i;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j]<<"\t";
        }
        cout << endl;
    }

    // Transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){   //use  j<i+1 not j<3 because you will get same result and only uuper half or lower half matrix is used in transpose 
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    cout<<endl;

    // OUTPUT
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j]<<"\t";
        }
        cout << endl;
    }


    return 0;
}
