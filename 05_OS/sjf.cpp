#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int id[n], at[n], bt[n], wt[n], tat[n], k[n];
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
        cout << "arrival : ";
        cin >> at[i];
        cout << "burst time : ";
        cin >> bt[i];
    }

    // SortAT
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(at[j] > at[j + 1]){
                swap(id[j], id[j + 1]);
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
            }
        }
    }

    int total = 0;
    for(int i = 0; i < n; i++){
        // SortBT
        for(int j = 0; j < n - 1; j++){
            for(int k = 0; k < n - 1; k++){
                if(bt[k] != 0 && at[k] <= total && at[k + 1] <= total){
                    if(bt[k] > bt[k + 1]){
                        swap(id[k], id[k + 1]);
                        swap(at[k], at[k + 1]);
                        swap(bt[k], bt[k + 1]);
                    }
                }
            }
        }

        // Calculation
        if (total >= at[i]){
            wt[i] = total - at[i];
        }
        else{
            total = at[i];
            wt[i] = 0;
        }
        total += bt[i];
        tat[i] = bt[i] + wt[i];

        k[i] = bt[i];
        bt[i] = 0;
    }

    cout << "id\tat\tbt\twt\ttat\n";
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << "\t" << at[i] << "\t" << k[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << endl;
    }

    cout << total;
    return 0;
}
