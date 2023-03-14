#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>

using namespace std;

struct Node{
            int data; //make it template
            Node* next;
            Node* prev;
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList();
        DoublyLinkedList(const DoublyLinkedList& dll);
        ~DoublyLinkedList();
        DoublyLinkedList& operator=(const DoublyLinkedList& dll);
        void push(int data);
        void insert(int data, int index);
        void pop();
        int size();
        void remove(int index);
        void print();
        int& at(int index);
};

#endif