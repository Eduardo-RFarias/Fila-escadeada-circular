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

        process.timeLeft *= 1000;

        list.add(process);
    }

    int time = 0;

    for (auto node = list.next(); !list.isEmpty(); node = list.next())
    {
        Process *process = &node->data;

        process->timeLeft -= quantum;
        time += quantum;

        if (process->timeLeft <= 0)
        {
            time += process->timeLeft;
            cout << process->id << " (" << time << ")" << endl;
            list.deleteCurrent();
        }
    }

    return 0;
}