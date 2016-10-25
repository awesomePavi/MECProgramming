/*
 * File:   main.cpp
 * Author: EricKamada
 * Integrated: Pavithran Pathmarajah
 *
 * Created on October 22, 2016, 6:31 PM
 */
#include "DataProcess.h"
#include <cstdlib>
#include <iostream>
using namespace std;



bool data :: getpriority(data x)    // returns priority of data class x
{
    bool b=x.priority;
    return priority;
}



queue :: queue()
{
    node* back = new node;
    back -> num =0;
    node* front = new node;
    front ->num = 0;
}

void queue :: enqueue(char* message)
{
    node* temp = new node;
    temp ->message = message;
    temp -> next=back;
    if (front -> num == 0)
    {
        cout << "sup";
       // front = temp;

    }
    else { back = temp;}

    //back = temp;
}

int queue :: dequeue(){
    node *temp = new node;
    char val;
    if(front == NULL){
        cout<<"\nQueue is Emtpty\n";
    }else{
        temp = front;
        val = *temp ->message;
        front = front->next;
        cout<<"The data Dequeued is "<<temp->message;
        delete temp;
    }
    return val;
}

int mainn() {

    // data values w and c are test variables used to verify code worked as expected

    char m1[30]="hey its sunny";
    char m2[30]="currents moving south 15km/h";
    data w;
    w.type ='w';    //represents  weather info
    w.message=m1;
    w.priority=0;

    data c;
    w.type = 'c';       //represents current info
    w.message=m2;
    w.priority=0;



    int p=1;
    int x=queues(w);

    return 0;
}

queue weather;
queue current;

int queues (data info)  //one queue for weather and one queue for current
{

    char* mess=info.message;
    if(info.type == 'w') //type is used here to determine which queue message will be inserted into
    {
        weather.enqueue(mess);
    }
        // queues will fill up with messages to be sent
    else
    {
        current.enqueue(mess);
    }

    return info.priority; // the priority of the info will be returned
}

queue weatherQueue(){
    return weather;
}

queue currentQueue(){
    return current;
}




