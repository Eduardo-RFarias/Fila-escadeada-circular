#ifndef CIRCULAR_LINKED_QUEUE_LIST_H
#define CIRCULAR_LINKED_QUEUE_LIST_H

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
class CircularLinkedQueue
{
private:
    Node<T> *head;
    Node<T> *tail;

    Node<T> *lastIteration;
    Node<T> *currentIteration;

public:
    CircularLinkedQueue()
    {
        head = nullptr;
        tail = nullptr;

        lastIteration = nullptr;
        currentIteration = nullptr;
    }

    ~CircularLinkedQueue()
    {
        Node<T> *temp = head;

        while (temp != nullptr)
        {
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void add(T data)
    {
        Node<T> *newNode = new Node<T>;

        newNode->data = data;
        newNode->next = nullptr;

        // If the list is empty
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    Node<T> *next()
    {
        // If the list is empty or next was never called before
        // then set the current iteration to the head.
        // lastIteration is set to nullptr to indicate that there is not a previous element.
        //
        // This if is also called if the currentIteration is the last element of the list
        // in this case, it's the same as if the list was empty, the next element is the first.
        if (currentIteration == nullptr || currentIteration->next == nullptr)
        {
            lastIteration = nullptr;
            currentIteration = head;

            return currentIteration;
        }

        lastIteration = currentIteration;
        currentIteration = currentIteration->next;

        return currentIteration;
    }

    void deleteCurrent()
    {
        // If the list is empty or next was never called before
        // we can't delete anything because we don't know what to delete.
        if (currentIteration == nullptr)
        {
            throw "List is empty or was not iterated yet";
        }

        // If the element to delete is the first element of the list
        // set the head to the next element and delete the current element.
        //
        // also, set currentIteration to nullptr to indicate make next() return the first element.
        if (currentIteration == head)
        {
            head = currentIteration->next;
            delete currentIteration;
            currentIteration = nullptr;

            return;
        }

        // If the element to delete is the last element of the list
        // set the tail to the previous element and delete the current element.
        //
        // also, set currentIteration to the last element to indicate make next() return the first element.
        if (currentIteration->next == nullptr)
        {
            tail = lastIteration;
            tail->next = nullptr;
            delete currentIteration;
            currentIteration = lastIteration;

            return;
        }

        // if the element to delete is in the middle of the list
        // just set the next of the last element to the next of the current element
        // also, make currentIteration point to the last element to make next() return the next element.

        lastIteration->next = currentIteration->next;
        delete currentIteration;
        currentIteration = lastIteration;
    }
};

#endif