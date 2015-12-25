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

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    T pop();
    T push(T newval);
private:
    struct Element {
        T value;
        struct Element *next;
    };
    
    struct Element *head;
};

template <typename T>
Stack<T>::Stack(){
    head = NULL;
    return;
}

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

template <typename T>
T Stack<T>::push(T newval){
    Element *elem = new Element;
    //allocation error will throw exception
    elem->value = newval;
    elem->next = head;
    head = elem;
    return newval;
}

template <typename T>
T Stack<T>::pop(){
    T data;
    if(head == NULL){
        //this could be handled via assert for a more strict error handling approach
        std::cerr << "ERROR:  pop() called on empty stack!  Returning -1 for value!\n";
    }else{
        struct Element *temp;
        data = head->value;
        temp = head->next;
        delete head;
        head = temp;
    }
    return data;
}

int main(int argc, const char * argv[]){
    int currentval;
    //build the stack
    class Stack<int> *head = new Stack<int>;
    
    //push and pop 'iterations' elements
    int iterations = 10;
    for(int i=1;i<=iterations;i++){
        head->push(i);
        currentval = head->pop();
        printf("%d-th pop of stack, expected value of %d, found: %d\n",i, i, currentval);
    }
    
    //testing popping the empty stack
    head->pop();
    
    delete head;
    return 0;
}











