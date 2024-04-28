// Reverse the elements of an array
#include <iostream>
using namespace std;

int main(){
    int arr[10];
    int temp;

    // Creating an array
    for (int i=0; i<10; i++){
        cin>>arr[i];
    }

    for(int i=0; i<10/2; i++){
        temp=arr[i];
        arr[i]=arr[9-i];
        arr[9-i]=temp;
    }


    //Printing
    for (int i = 0; i < 10; i++){
        cout<<arr[i]<<endl;
    }
    

}