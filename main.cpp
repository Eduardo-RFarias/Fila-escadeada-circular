#include <iostream>
#include "lib/circular-linked-queue.hpp"

using namespace std;

struct Process
{
    int id;
    int timeLeft;
};

int main()
{
    CircularLinkedQueue<Process> list;

    int numProcess;
    cin >> numProcess;

    int quantum;
    cin >> quantum;

    for (int i = 0; i < numProcess; i++)
    {
        Process process;

        cin >> process.id;
        cin >> process.timeLeft;

        // Convert to milliseconds
        process.timeLeft *= 1000;

        list.add(process);
    }

    int time = 0;

    // Iterate over the queue until it's empty
    for (auto node = list.next(); !list.isEmpty(); node = list.next())
    {
        // Get the process from the node
        Process *process = &node->data;

        // Subtract the quantum from the process time and add it to the total time
        process->timeLeft -= quantum;
        time += quantum;

        // If after subtracting the quantum the process time is less than or equal to 0
        // then the process is done and we can print it
        if (process->timeLeft <= 0)
        {
            // Maybe the process took less than the quantum to finish
            // so we need to add the remaining time to the total time
            // in this case the remaining time is the negative value of the process time
            time += process->timeLeft;
            cout << process->id << " (" << time << ")" << endl;
            list.deleteCurrent();
        }
    }

    return 0;
}