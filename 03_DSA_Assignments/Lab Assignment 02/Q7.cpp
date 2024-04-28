#include<iostream>
using namespace std;

int main()
{
    int size,inversions=0;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements in the array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i<j&&arr[i]>arr[j])
            {
                inversions++;
            }
        }       
    }
    cout<<"Number of inversions = "<<inversions<<endl;

    return 0;

}