#include<iostream>
using namespace std;

struct process{
    int id, at,bt, wt, ct, tat, p, rt;
    process(){};
    process(int id, int at, int bt)
    {
        this->id= id;
        this->at= at;
        this->bt= bt;
        this->rt= bt;
        this->p= id;
    }
};

void input(process arr[], int n)
{
    int at,bt,p;
    for(int i=1;i<=n;i++)
    {
        at=0;
        bt=0;
        cout<<"Enter the Arrival time for process "<<i<<endl;
        cin>>at;
        cout<<"Enter the Burst time for process "<<i<<endl;
        cin>>bt;
        arr[i-1]=process(i,at,bt);
        cout<<"Enter the Priority for process "<<i<<endl;
        cin>>arr[i-1].p;
    }
}

void swap(process *xp, process *yp)
{
    process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortArrivalTime(process arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].at > arr[j+1].at)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void priority_sort(process arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j].p < arr[j+1].p)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void non_preemptive_priority(process arr[], int n)
{
    input(arr, n);
    sortArrivalTime(arr, n);
    priority_sort(arr, n);
    int time = 0;
    int avgWt = 0;
    for(int i=0;i<n;i++)
    {
        arr[i].wt = time - arr[i].at;
        if (arr[i].wt < 0)
        {
            arr[i].wt = 0;
            time = arr[i].at;
        }
        time += arr[i].bt;
        arr[i].ct = time - arr[i].at;
        arr[i].tat = time - arr[i].at;
        avgWt += arr[i].wt;
    }
}

int main()
{
    
    return 0;
}