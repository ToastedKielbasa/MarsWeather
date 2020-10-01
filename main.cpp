/*
    Tyler Scott
    Mars Weather (Project 1)
    *****************************
    Main
    - Implements a queue data structure on different data types
    - Prints each to console
*/

#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "Weather.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**
    Outputs the vector contents
    @param weather Variable holding vector
*/
void displayVectorContents(vector<MarsWeather> &weather) {

    for (int i = 0; i < weather.size(); ++i) {
        cout << weather[i] << endl;
    }
}

/**
    Calculates the average maximum temperature
    @param weather Variable holding vector
    @param vectorSize Total number of rows; used to divide by temperature total
*/
void averageMax(vector<MarsWeather> &weather, int vectorSize) {

    int total = 0;
    int avg_total;

    for (int i = 0; i < weather.size(); ++i) {

        int temp;
        temp = weather[i].getMaxTemp();
        total = temp + total;
    }

    avg_total = total / vectorSize;
    cout << "\n" << "Average Maximum Temperature: " << avg_total << endl;
}

/**
    Calculates the average minimum temperature
    @param weather Variable holding vector
    @param vectorSize Total number of rows; used to divide temperature total by row size
*/
void averageMin(vector<MarsWeather> &weather, int vectorSize) {

    int total = 0;
    int avg_total;

    for (int i = 0; i < weather.size(); ++i) {

        int temp;
        temp = weather[i].getMinTemp();
        total = temp + total;
    }

    avg_total = total / vectorSize;
    cout << "\n" << "Average Minimum Temperature: " << avg_total << endl;
}

int main() {

    // Variable for number of rows of vector to loop through
    int const row_num = 10;

    // Create vector object
    vector<MarsWeather> weather;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);

    // Queue of integers
    Queue<int> intQueue;
    intQueue.enqueue(9);
    intQueue.enqueue(14);
    intQueue.enqueue(47);
    intQueue.enqueue(26);
    intQueue.printQueue();
    cout << boolalpha;
    cout << "\n" << "Is 9 in queue? " << intQueue.isInQueue(9) << endl;
    intQueue.dequeue();
    cout << "\n" << "Dequeue called, should remove first Node (9): " << endl;
    intQueue.printQueue();
    cout << "\n" << "Is 9 in queue? " << intQueue.isInQueue(9) << endl;

    // Queue of strings
    Queue<string> stringQueue;
    stringQueue.enqueue("One");
    stringQueue.enqueue("Two");
    stringQueue.enqueue("Three");
    stringQueue.enqueue("Four");
    stringQueue.printQueue();
    cout << "\n" << "Is One in queue? " << stringQueue.isInQueue("One") << endl;
    stringQueue.dequeue();
    cout << "\n" << "Dequeue called, should remove first Node (One): " << endl;
    stringQueue.printQueue();
    cout << "\n" << "Is One in queue? " << stringQueue.isInQueue("One") << endl;

    // Queue implementation
    Queue<MarsWeather> vectorQueue;
    for (int i = 0; i < row_num; ++i) {
        vectorQueue.enqueue(weather[i]);
    }
    cout << "\n" << "Furthest left column is in descending order in CSV. Queue retains original order (FIFO) by appending elements to the last Node" << endl;
    vectorQueue.printQueue();

    cout << "\n" << "Dequeue all elements out of queue, now empty" << endl;
    for(int i = 0; i < row_num; ++i) {
        vectorQueue.dequeue();
    }
    vectorQueue.printQueue();

    // Stack implementation
    Stack<MarsWeather> vectorStack;
    for (int i = 0; i < row_num; ++i) {
        vectorStack.push(weather[i]);
    }
    cout << "\n" << "Furthest left column is in descending order in CSV. Stack reverses original order (LIFO) by appending elements to the first Node" << endl;
    vectorStack.printStack();

    cout << "\n" << "Pop all elements out of stack, now empty" << endl;
    for(int i = 0; i < row_num; ++i) {
        vectorStack.pop();
    }
    vectorStack.printStack();

    return 0;
}



