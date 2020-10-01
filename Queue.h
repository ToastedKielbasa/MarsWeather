/*
    Tyler Scott
    Mars Weather (Project 1)
    *****************************
    Queue class
    - Methods for adding, removing, searching, and printing contents of a queue

*/

#ifndef PROJECT_1_WEATHERQUEUE_H
#define PROJECT_1_WEATHERQUEUE_H

#include <iostream>
#include <vector>
#include "Node.h"
#include "weather.h"

template<typename Object>

class Queue {

private:

    Node<Object>* first;
    Node<Object>* last;

public:

    Queue() {

        first = nullptr;
        last = nullptr;
    }

    ~Queue() {

        while (first != nullptr) {

            dequeue();
        }
    }

    /**
        Adds new elements to queue
        @param item Element to be added
     */
    void enqueue(Object item) {

        // Store Node in heap memory via "new" keyword
        Node<Object> *newNode = new Node<Object>(item);

        if (first == nullptr) {
            first = newNode;
            last = newNode;
        }

        else {
            last->setNext(newNode);
            last = newNode;
        }

        // Delete Node in heap to stop memory leak (This makes queue unable to take in MarsWeather type?)
        //delete newNode;

    }

    /**
        Removes item from queue
        @return The new first item
     */
    Object dequeue() {

        // Create Object type to add contents of first Node in queue
        Object newFirst = first->getItem();

        // Move second node ot first position
        first = first->getNext();

        // When first is null, list is empty so change last to null
        if (first == nullptr) {
            last = nullptr;
        }

        return newFirst;

    }

    /**
       Prints all contents in queue
     */
    void printQueue() {

        std::cout << "\n" << "Beginning of Queue" << std::endl;

        Node<Object>* curr = first;

        while (curr != nullptr) {
            std::cout << curr->getItem() << std::endl;
            curr = curr->getNext();
        }

        std::cout << "End of Queue" << std::endl;
        delete curr;
    }

    /**
       Searches through queue to find specific item
       @param item The item to be searched for
       @return
     */
    bool isInQueue(Object item) {

        Node<Object>* curr = first;

        while (curr != nullptr) {
            if (curr->getItem() == item) {
                return true;
            }
            curr = curr->getNext();
        }

        delete curr;
        return false;
    }
};

#endif //PROJECT_1_WEATHERQUEUE_H
