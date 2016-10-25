//
// Created by Pavi on 2016-10-22.
//
#include <iostream>
#include <thread>
#include <chrono>
#include "Selector.h"
#include "Encoder.h"
#include "Setup.h"

void Selector::print(){
    std::cout << "hi";
}



int Selector::mainLoop(Setup access){
    bool run = true;
    //boolean true is weather false is current
    bool next = false;

    char tmp[255] = "Blank";
    char* message = tmp;
    char* encodedMessage;
    Encoder msgEncode;
    int messagesSent = 0;

    while (run){
        if (messagesSent > 50){
            access.testHardware();
        }



        if (!(access.weatherQueue ->hasInfo()) &&  !(access.currentQueue ->hasInfo())){
        }else if (!(access.weatherQueue ->hasInfo()) &&  (access.currentQueue ->hasInfo())){
            message = access.currentQueue -> dequeue();
        }else if ((access.weatherQueue ->hasInfo()) &&  !(access.currentQueue ->hasInfo())){
            message = access.weatherQueue -> dequeue();
        }else {
            if (access.weatherQueue -> getPriority() && access.currentQueue -> getPriority()) {
                if (next){
                    message = access.weatherQueue -> dequeue();
                }else{
                    message = access.currentQueue -> dequeue();
                }
                next = !next;
            }else if (access.weatherQueue -> getPriority()){
                message = access.weatherQueue -> dequeue();
            }else if (access.currentQueue -> getPriority()) {
                message = access.currentQueue -> dequeue();
            }else if (next){
                message = access.weatherQueue -> dequeue();
                next = !next;
                //no emergencies, broadcast current next
            }else{
                message = access.currentQueue -> dequeue();
                next = !next;
            }
        }



        encodedMessage = msgEncode.encodeString(message);
        access.broadcaster.broadCast(encodedMessage);
        messagesSent++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}