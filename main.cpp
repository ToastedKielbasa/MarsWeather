/*
    Tyler Scott
    Mars Weather (Project 1)
    *****************************
    Main
    - Takes in Objects and methods from Weather.h
    - Creates vector of data received
    - Applies functions that calculates the average maximum and minimum temperatures
*/

#include "Weather.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
    Outputs the vector contents
    @param weather Variable holding vector
*/
void displayVectorContents(vector<MarsWeather> &weather) {

    for (int i = 0; i < weather.size(); ++i) {
        cout << weather[i] << endl;
    }
}

/*
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

/*
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

    // Create vector object
    vector<MarsWeather> weather;

    // Populate vector with content from file
    getWeather("mars-weather.csv", weather);


    // Show vector
    displayVectorContents(weather);

    // Displays the average maximum temperature
    averageMax(weather, weather.size());
    averageMin(weather, weather.size());

    // Displays vector size
    cout << "\n" << "Size of Vector: " << weather.size() << endl;

    return 0;
}


