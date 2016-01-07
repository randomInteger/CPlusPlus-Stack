//
//  main.cpp
//  C++_Stack
//
//  A very basic template data type stack class, implemented
//  via a singly linked list.
//
//  Created by Christopher Gleeson on 12/20/15.
//  Copyright © 2015 Christopher Gleeson. All rights reserved.
//

#include <iostream>
#include <exception>

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    bool pop(T *value);
    bool push(T newval);
private:
    struct Element {
        T value;
        struct Element *next;
    };
    
    struct Element *head;
};

//Constructor
template <typename T>
Stack<T>::Stack(){
    head = NULL;
    return;
}

//Destructor
template <typename T>
Stack<T>::~Stack(){
    Element *next;
    while(head !=NULL){
        next = head->next;
        delete head;
        head = next;
    }
    return;
}

//Pushes a new value onto the stack
//Returns:  true on success, false on failure to allocate memory.
template <typename T>
bool Stack<T>::push(T newval){
    Element *elem;
    try {
        elem = new Element;
    } catch (std::bad_alloc& exc) {
        std::cerr << "ERROR: could not allocate storage.\n";
        //we could call std::terminate() here instead.
        return false;
    }
    elem->value = newval;
    elem->next = head;
    head = elem;
    return true;
}

//Pops a value from the stack.
//Returns:  true on success, false on empty stack.
template <typename T>
bool Stack<T>::pop(T *value){
    if(head == NULL){
        std::cerr << "ERROR:  pop() called on empty stack!  Returning false.\n";
        return false;
    }else{
        struct Element *temp;
        *value = head->value;
        temp = head->next;
        delete head;
        head = temp;
    }
    return true;
}

int main(int argc, const char * argv[]){
    int value = 0;
    int *valptr = &value;
    bool respush = false;
    bool respop = false;
    
    //build the stack
    //TODO TRY.
    class Stack<int> *myStack;
    try {
        myStack = new Stack<int>;
    } catch (std::bad_alloc& exc) {
        std::cerr << "WARNING, FAILURE TO ALLOCATE, TERMINATING!\n";
        std::terminate();
    }
    
    //push items onto the stack
    int iterations = 10;
    for(int i=1;i<=iterations;i++){
        respush = myStack->push(i);
        if(respush == false){
            std::cout << "Error, respop returned " << respop << "\n";
        }else{
            std::cout << i << "-th push of the stack, successfully pushed value " << i <<"\n";
        }
    }
    std::cout << "\n";
    
    //pop items from the stack
    for(int i=1;i<=iterations;i++){
        respop = myStack->pop(valptr);
        if(respop == false){
            std::cout << "Error, respush returned " << respush << "\n";
        }else{
            std::cout << i << "-th pop of the stack, expected value of " << i << " found: " << *valptr << "\n";
        }
    }
    
    //testing popping the empty stack
    myStack->pop(valptr);
    
    delete myStack;
    return 0;
}











