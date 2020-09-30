//
// Created by tyler on 9/25/2020.
//

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

    void enqueue(Object item) {

        Node<Object>* newNode = new Node<Object>(item);

        if (last != nullptr) {
            last->setNext(newNode);

        }

        last = newNode;

        if (first == nullptr) {
            first = newNode;
        }



        //else {
        //    last = newNode;
        //}

    }

    Object dequeue() {

        //
        Object removed = first->getItem();
        // Move second node ot first position
        first = first->getNext();
        // When first is null, list is empty so change last to null
        if (first == nullptr) {
            last = nullptr;
        }

        return removed;

    }

    void printQueue() {
        std::cout << "Beginning of Stack" << std::endl;
        // Make a copy of top
        Node<Object>* curr = first;
        while (curr != nullptr) {
            std::cout << curr->getItem() << std::endl;
            curr = curr->getNext();
        }
        std::cout << "End of Stack" << std::endl;
    }

    bool isInQueue(Object item) {

        Node<Object>* curr = first;

        while (curr != nullptr) {
            // This will require you to overload the == operator
            if (curr->getItem() == item) {

                return true;
            }
            curr = curr->getNext();
        }

        return false;
    }
};

#endif //PROJECT_1_WEATHERQUEUE_H
