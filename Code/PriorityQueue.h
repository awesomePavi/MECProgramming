//
// Created by Pavi on 2016-10-24.
//

#ifndef TMP_PRIORITYQUEUE_H
#define TMP_PRIORITYQUEUE_H

class Node{
public:
    Node* Next;
    char* msg;
    bool priority;
};

class PriorityQueue {
private:
    Node* last;
    int size;
public:
    PriorityQueue();
    void queue( bool, char*);
    char* dequeue();
    bool getPriority();
    bool hasInfo();
};


#endif //TMP_PRIORITYQUEUE_H
