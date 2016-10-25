/* 
 * File:   main.cpp
 * Author: EricKamada
 *
 * Created on October 22, 2016, 6:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include "Setup.h"
#include "Selector.h"
#include "PriorityQueue.h"


using namespace std;

void loop(Setup setup){
    Selector loop;
    loop.mainLoop(setup);
}

void genWeather(Setup access){
    char messages[10][255] = {
            {"Great Weather"},
            {"Sunny"},
            {"Cloudy"},
            {"Cold"},
            {"HOTT"},
            {"Wet"},
            {"Musky"},
            {"Humid"},
            {"Dry"},
            {"Salty"}};


    int iterations =0;
    while (iterations < 50) {
        iterations++;
        bool boolVal = (rand() % 50) == 25;
        access.DataIn('c', boolVal, messages[rand() % 10]);
        this_thread::sleep_for(chrono::seconds(rand() % 2));
    }
}

void genCurrent(Setup access) {
    char messages[10][255] = {
    {"North"},
    {"South"},
    {"East"},
    {"West"},
    {"North East"},
    {"North West"},
    {"South East"},
    {"South West"},
    {"UP"},
    {"Down"}};


    int iterations =0;
    while (iterations < 50) {
        iterations++;
        bool boolVal = (rand() % 50) == 25;
        access.DataIn('c', boolVal, messages[rand() % 10]);
       this_thread::sleep_for(chrono::seconds(rand() % 2));
    }
}

int main(int argc, char** argv) {
    cout << "start" <<endl;




    Setup setup;
    setup.setUp();

    thread module(loop,setup);
    thread weatherGen (genWeather,setup);
    thread currentGen (genCurrent,setup);
    weatherGen.join();
    currentGen.join();
    module.join();

    return 0;
}



