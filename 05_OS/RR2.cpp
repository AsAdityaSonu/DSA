#include <iostream>
using namespace std;

void find_waiting_time(int processes[], int n, int bt[], int wt[], int quantum, int at[])
{
    int remaining_bt[n];
    int remaining_at[n];
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        remaining_bt[i] = bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        remaining_at[i] = at[i];
    }
    while (true)
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (remaining_at[i] == 0)
            {

                if (remaining_bt[i] > 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (remaining_at[j] > 0 && remaining_bt[i] > quantum)
                        {
                            remaining_at[j] -= quantum;
                        }
                        else if (remaining_at[j] > 0 && remaining_bt[i] <= quantum)
                        {
                            remaining_at[j] -= remaining_bt[i];
                        }
                        if (remaining_at[j] <= 0)
                            remaining_at[j] = 0;
                    }
                    flag = 1;
                    if (remaining_bt[i] > quantum)
                    {

                        remaining_bt[i] -= quantum;
                        t += quantum;
                    }
                    else
                    {
                        t += remaining_bt[i];
                        remaining_bt[i] = 0;
                        wt[i] = t - bt[i] - at[i];
                    }
                }
            }
        }
        if (flag == 0)
            break;
    }
}
void find_turn_around_time(int processes[], int n, int bt[], int wt[], int tat[], int at[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void run(int processes[], int bt[], int n, int quantum, int at[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    find_waiting_time(processes, n, bt, wt, quantum, at);
    find_turn_around_time(processes, n, bt, wt, tat, at);
    cout << "PN\tBT\tWT\tTAT\tAT" << endl;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << at[i] << endl;
    }
    cout << "Average wait time = " << (float)total_wt / (float)n << endl;
    cout << "Average Turn Around time = " << (float)total_wt / (float)n;
}
int main()
{
    cout << "Enter the no. of processes :-";
    int n;
    cin >> n;
    int processes[n];
    cout << "Enter the time quanta:- ";
    int quanta;
    cin >> quanta;
    cout << "Enter the burst time for each process :-" << endl;
    int bt[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i + 1 << " :- ";
        cin >> bt[i];
    }
    cout << "Enter the arrival time for each process :-" << endl;
    int at[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for process " << i + 1 << " :- ";
        cin >> at[i];
    }
    run(processes, bt, n, quanta, at);
    return 0;
}