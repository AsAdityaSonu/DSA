// // Multiplication of matrix

// #include<iostream>
// using namespace std;

// int main()
// {
//     int a[3][3], b[3][3];
//     cout<<"Enter the elements of the first array";
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             cin >> a[i][j];
//         }
//     }
//     cout<<"Enter the elements of the second array";
//     for(int i=0;i<3;i++){
//         for (int j = 0 ; j < 3; j++)
//         {
//             cin>> b[i][j];
//         }
//     }

//     int r[3][3];
//     // Multiplying arrays
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             r[i][j] =0;
//             for(int k=0;k<3;k++){
//                 r[i][j]=a[i][k]*b[k][j];
//             }
//         }
//     }

//     for(int i=0;i<3;i++){
//         for (int j = 0 ; j < 3; j++)
//         {
//             cout<< r[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


#include <iostream>  
using namespace std;  
int main()  {  
    int a[10][10],b[10][10];
    int res[10][10];
    int n;
    int i,j,k;    

    cout<<"Enter No. of rows and columns";
    cin>>n;

    cout<<"first matrix\n";    
    for(i=0;i<n;i++){    
        for(j=0;j<n;j++){    
            cin>>a[i][j];  
        }    
    }    


    cout<<"second matrix\n";    
    for(i=0;i<n;i++){    
        for(j=0;j<n;j++){    
            cin>>b[i][j];    
        }    
    } 


    cout<<"multiply of the matrix=\n";    
    for(i=0;i<n;i++){    
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){    
                res[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }    


    //result    
    for(i=0;i<n;i++){    
        for(j=0;j<n;j++){    
            cout<<res[i][j]<<" ";    
        }    
        cout<<"\n";    
    }    
    return 0;  
}    