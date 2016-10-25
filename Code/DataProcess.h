/*
 * File:   main.cpp
 * Author: EricKamada
 * Integrated: Pavithran Pathmarajah
 *
 * Created on October 22, 2016, 6:31 PM
 */

#ifndef TMP_DATAPROCESS_H
#define TMP_DATAPROCESS_H

//the type value is used to determine which queue information will go to

class data{         //data has three values , information type , priority and message to be broadcast
public:
    char* message;      // this is what will be queued and eventually broadcast out
    bool priority;      // this determines if the message is urgent or not
    char type;          // the information can in regards to weather ('w') or current ('w')
    bool getpriority(data x); // method used to get the priority of the selected data class
};

struct node{    // queue will be implemented using linked lists

    char* message;
    int num;
    node* next;
};

// queue was implemented following the template found in the link below
// http://code.runnable.com/U5n_ei3uhWBxOqiT/queue-implementation-using-linked-list-for-c%2B%2B

class queue{
private:
    node* front;
    node* back;

public:

    queue();
    void enqueue(char* p);
    int dequeue();
};


int queues (data info); //initialization for queue

queue weatherQueue();
queue currentQueue();


#endif //TMP_DATAPROCESS_H
