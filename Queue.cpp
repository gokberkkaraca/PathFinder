//--------------------------------------------------------------------
// Title: Queue.cpp
// Author: Sabit Gökberk Karaca
// ID: 21401862
// Section: 3
// Assignment: 4
// Description: Implementation of Queue class
//--------------------------------------------------------------------

#include "Queue.h"
#include <iostream>
using namespace std;

// Constructor
Queue::Queue(){
    head = NULL;
    tail = NULL;
}

// Copy Constructor
Queue::Queue(const Queue& oldQueue){
    if ( oldQueue.head == NULL){
        head = NULL;
        tail = NULL;
    }
    else{

        // Create the first node
        Node* cur = new Node;
        cur->item = oldQueue.head->item;
        cur->next = NULL;
        head = cur;

        // Do the rest
        Node* oldCur = oldQueue.head->next;
        while (oldCur != NULL){
            Node* newNode = new Node;
            newNode->item = oldCur->item;
            newNode->next = NULL;
            cur->next = newNode;
            cur = newNode;
            oldCur = oldCur->next;
        }

        tail = cur;
    }
}

// Destructor
Queue::~Queue(){
    while (!isEmpty())
        dequeue();
}

// Check if it is empty or not
bool Queue::isEmpty(){
    return head == NULL;
}

// Insert a new item to the end of queue
bool Queue::enqueue(ItemType item){

	// Create the new node
    Node* newNode = new Node;
    newNode->item = item;
    newNode->next = NULL;

    // Adding to first node
    if ( head == NULL)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;

    return true;
}

// Remove an item from the front of the queue
bool Queue::dequeue(){

    if (isEmpty())
        return false;
    else {
    	// Delete the node
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

// Remove an item from the front of the queue and return the item
bool Queue::dequeue(ItemType& item){
    if (isEmpty())
        return false;
    else {
    	// Delete and return the item
        item = head->item;
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

// Get the front item without deleting it
bool Queue::getFront(ItemType& item){
    if (isEmpty())
        return false;
    else{
        item = head->item;
        return true;
    }
}

// Print the queue
void Queue::display(){

	// Iterate over the queue
    Node* cur = head;
    while(cur != NULL){
        cout << cur->item << " ";;
        cur = cur->next;
    }

    cout << endl;
}


