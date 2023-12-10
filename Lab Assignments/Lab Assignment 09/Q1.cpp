#include<iostream>
using namespace std;

class heap{
    public:
    int size;
    int arr[100];

    void insert(int val);
    void del();
    void print();
    void heapify(int a[],int n, int i);
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

void heapify(int a[], int n, int i){
    int largest=i;
    int left = 2*i;
    int right=2*i+1;

    if(left<n && a[left]>a[largest]){
        largest = left;
    }

    if(right<n && a[right]>a[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
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


    int arr[6]={-1,54,53,55,52,50};
    int n=6;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    return 0;
}
