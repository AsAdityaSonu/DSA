#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
};

void roundRobin(vector<Process> &processes, int quantum)
{
    queue<Process> readyQueue;
    int currentTime = 0;

    cout << "Execution Sequence:" << endl;

    while (!processes.empty() || !readyQueue.empty())
    {
        // Add any newly arrived processes to the ready queue
        for (size_t i = 0; i < processes.size(); ++i)
        {
            if (processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0)
            {
                readyQueue.push(processes[i]);
                processes.erase(processes.begin() + i);
            }
        }

        // No processes left to execute
        if (readyQueue.empty())
        {
            break;
        }

        // Execute process at the front of the ready queue for quantum time
        Process current = readyQueue.front();
        readyQueue.pop();
        int burst = min(quantum, current.burstTime);

        cout << "Executing Process " << current.id + 1 << " for time quantum " << burst << endl;

        currentTime += burst;
        current.burstTime -= burst;

        if (current.burstTime > 0)
        {
            // Process not finished, add back to ready queue
            readyQueue.push(current);
        }
    }
}

int main()
{
    vector<Process> processes;

    Process p1 = {0, 0, 3};
    Process p2 = {1, 1, 4};
    Process p3 = {2, 5, 2};
    Process p4 = {3, 3, 5};

    processes.push_back(p1);
    processes.push_back(p2);
    processes.push_back(p3);
    processes.push_back(p4);

    int quantum = 4;

    roundRobin(processes, quantum);

    return 0;
}
