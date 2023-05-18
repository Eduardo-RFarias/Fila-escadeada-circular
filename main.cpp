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

    list.add({1, 1000});
    list.add({2, 2000});
    list.add({3, 3000});

    for (auto node = list.next(); node != nullptr; node = list.next())
    {
        auto element = node->data;

        cout << "PID: " << element.id << endl;
        cout << "Time: " << element.timeLeft << endl;

        list.deleteCurrent();
    }

    list.add({4, 4000});
    list.add({5, 5000});
    list.add({6, 6000});

    auto p1 = list.next();
    cout << "PID: " << p1->data.id << endl;
    cout << "Time: " << p1->data.timeLeft << endl;

    auto p2 = list.next();
    cout << "PID: " << p2->data.id << endl;
    cout << "Time: " << p2->data.timeLeft << endl;

    auto p3 = list.next();
    cout << "PID: " << p3->data.id << endl;
    cout << "Time: " << p3->data.timeLeft << endl;

    list.deleteCurrent();

    p1 = list.next();
    cout << "PID: " << p1->data.id << endl;
    cout << "Time: " << p1->data.timeLeft << endl;

    p1 = list.next();
    cout << "PID: " << p1->data.id << endl;
    cout << "Time: " << p1->data.timeLeft << endl;

    p1 = list.next();
    cout << "PID: " << p1->data.id << endl;
    cout << "Time: " << p1->data.timeLeft << endl;

    return 0;
}