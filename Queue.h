//--------------------------------------------------------------------
// Title: Queue.h
// Author: Sabit Gökberk Karaca
// ID: 21401862
// Section: 3
// Assignment: 4
// Description: Header file of Queue class
//--------------------------------------------------------------------

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
using namespace std;

typedef int ItemType;

struct Node{
    ItemType item;
    Node* next;
};

class Queue{

public:

    Queue();
    Queue(const Queue& oldQueue);
    ~Queue();

    bool isEmpty();

    bool enqueue(ItemType item);
    bool dequeue();
    bool dequeue(ItemType& item);
    bool getFront(ItemType& item);

    void display();

private:
    Node* head;
    Node* tail;
};


#endif /* QUEUE_H_ */
