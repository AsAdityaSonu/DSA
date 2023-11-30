#include<iostream>
using namespace std;

class heap{
    public:
    int size;
    int arr[100];

    void insert(int val);
    void del();
    void print();
};

void heap::insert(int val){
    size++;
    int index=size;
    arr[index]=val;

    while(index>1){
        int parent = index/2;
        if(arr[parent]< arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }else{
            return;
        }
    }
}

void heap::del(){
    arr[1]=arr[size];
    size--;

    int i =1;

    while(i<size){
        int left = i*2;
        int right = i*2+1;

        if(left<size && arr[left]>arr[i]){
            swap(arr[i],arr[left]);
            i=left;
        }else if(right<size && arr[right]>arr[i]){
            swap(arr[i],arr[right]);
            i=right;
        }else{
            return;
        }
    }

}

void heap::print(){
    for (int i=1;i<=size;i++){
        cout<<arr[i];
    }
}

int main()
{
    heap h;
    h.insert(2);
    h.insert(20);
    h.insert(3);
    h.insert(8);
    h.print();
    h.del();
    h.print();
    return 0;
}