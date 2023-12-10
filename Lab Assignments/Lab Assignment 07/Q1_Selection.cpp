#include<iostream>
using namespace std;

int main()
{
    int a[]={6,7,2,3,5};
    int n=5;

    for(int i=0;i<n;i++){
        int min= i;
        for (int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        if(min!=i){
            swap(a[i],a[min]);
        }
    }

    for(int i =0 ;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}