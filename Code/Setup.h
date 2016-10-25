//
// Created by Pavi on 2016-10-22.
//

#ifndef TMP_SETUP_H
#define TMP_SETUP_H


#include "Broadcaster.h"
#include "PriorityQueue.h"

class Setup {
public:
    int setUp();
    void testHardware();
    Broadcaster broadcaster;
    PriorityQueue* weatherQueue;
    PriorityQueue* currentQueue;
    void DataIn(char, bool, char*);
};


#endif //TMP_SETUP_H
