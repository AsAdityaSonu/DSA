// Design the logic to remove the duplicate elements from an Array and after the
// deletion the array should contain the unique elements.

#include <iostream>
using namespace std;

int main(){
    vector<int> arr;
    int num;
    cout<<"Enter the number of elements: ";
    cin >> num;
    arr.resize(num);

    cout<<"Enter "<<arr.size()<<" element(s) for array: "<<endl;
    for(int i=0; i<num; i++){
        cin >> arr[i];
    }    
}