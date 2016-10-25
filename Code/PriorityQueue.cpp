//
// Created by Pavi on 2016-10-24.
//

#include "PriorityQueue.h"
#include <cstdlib>
#include <iostream>


PriorityQueue::PriorityQueue(void){
    last = NULL;
    size = 0;

}

void PriorityQueue::queue(bool priority, char * message) {
    if (size < 0)
        size =0;
    Node* tmp = new Node;
    tmp ->msg = message;
    tmp -> priority = priority;
    tmp -> Next = NULL;
    size++;
    if (size == 1) {
       // std::cout << "1" << std::endl << std::flush;
        last = tmp;
    }else if (priority){
        //std::cout << "2" << std::endl << std::flush;
        Node* tmpp = last;
        while (tmpp -> Next){
            tmpp = tmpp -> Next;
        }
        tmpp ->Next = tmp;
    }else{
        //std::cout << "3" << std::endl << std::flush;
        tmp -> Next = last;
        last= tmp;
    }
}

bool PriorityQueue::hasInfo(){
    return size > 0;
}

char* PriorityQueue::dequeue(){
    
    char* msg;
    try {
        //std::cout << last -> Next <<std::endl << std::flush;
        //std::cout << last -> msg <<std::endl << std::flush;
        Node* tmpLast;
        Node* tmp = last;
        while (tmp -> Next){
            tmpLast = tmp;
            tmp = tmp -> Next;
        }
        msg = tmp ->msg;
        tmpLast -> Next = NULL;
        size --;
    } catch (int e){

            char tmp[1] = "";
            msg= tmp;
    }
    return msg;
}

bool PriorityQueue::getPriority() {
    if (last = NULL){
        return false;
    }
    bool prior;
    try {
        Node* tmp = last;
        while (tmp -> Next){
            tmp = tmp -> Next;
        }
        prior = tmp ->priority;
    } catch (int e){
        char tmp[1] = "";
        prior = false;
    }
    return prior;
}