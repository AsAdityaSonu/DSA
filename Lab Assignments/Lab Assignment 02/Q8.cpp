#include<iostream>
using namespace std;

int main()
{
    int a[]={1,2,3,3,4,4,5,56,6,6};
    int size = sizeof(a)/sizeof(a[0]);
    int count=0;

    // cout<<size<<endl;
    for(int i=0;i<size ;i++){
        for(int j=0;j<size;j++){
            if(a[i]==a[j]){
                if(i==j){
                    cout<<a[i]<<"\t";
                    count++;
                }
                break;
            }
            
        }
    }
    cout<<endl;
    cout<<count<<endl;
    return 0;
}