#include<iostream>
using namespace std;

int main()
{
    int a[]={6,7,2,3,5};
    int n=5;
    int max = a[0];


    for (int i=0; i<n;i++){
        bool flag=true;     //for best case
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                flag = false;
                swap(a[j],a[j+1]);
            }
            
        }
        if(flag==true){
            break;
        }
    }

    for(int i =0;i<5;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}