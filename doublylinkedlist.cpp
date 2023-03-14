#include "doublylinkedlist.h"

/**
 * Default constructor for the DoublyLinkedList class.
 * 
 */
DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

/**
 * Copy  constructor for the DoublyLinkedList class.
 * 
 * @param dll the DoublyLinkedList to copy
 */
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll){
    head = NULL;
    tail = NULL;

    Node* temp = dll.head;
    while(temp != NULL){
        push(temp->data);
        temp = temp->next;
    }
}

/**
 * Destructor for the DoublyLinkedList class.
 * 
 */
DoublyLinkedList::~DoublyLinkedList(){
    Node* temp = head;
    while(temp != NULL){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}

/**
 * Overloaded assignment operator for the DoublyLinkedList class.
 * 
 * @param dll the DoublyLinkedList to copy
 * @return a reference to the current DoublyLinkedList
 */
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll){
    if(this != &dll){
        Node* temp = head;
        while(temp != NULL){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        
        head = NULL;
        tail = NULL;
        
        temp = dll.head;
        while(temp != NULL){
            push(temp->data);
            temp = temp->next;
        }
    }
    
    return *this;
}


/**
 * Appends a new node to the end of the DoublyLinkedList.
 * 
 * @param data the data to store in the new node
 */
void DoublyLinkedList::push(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}

/**
 * Removes the last node from the DoublyLinkedList.
 * 
 */
void DoublyLinkedList::pop(){
    if(head == NULL){
        return;
    }
    
    if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    
}

/**
 * Returns the number of nodes in the DoublyLinkedList.
 * 
 * @return int the number of elements in the DoublyLinkedList
 */
int DoublyLinkedList::size(){
    Node* temp = head;
    int count = 0;
    
    if(temp == nullptr){
        return count;
    }
    
    while(temp != nullptr){
        temp = temp->next;
        count++;
    }
    
    return count;
}

/**
 * Inserts a new node containing data at the specified index.
 * 
 * @param data The data to store in the new node
 * @param index The index at which to insert the new node
 */
void DoublyLinkedList::insert(int data, int index){
    if(index < 0 || index > size()){
        return;
    }
    
    if(index == 0){
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        
        if(head != NULL){
            head->prev = newNode;
        }
        
        head = newNode;
        
        if(tail == NULL){
            tail = newNode;
        }
        
    }else if(index == size()){
        push(data);
    }else{
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        Node* temp = head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        
    }
}

/**
 * Removes the node at the specified index.
 * 
 * @param index The index of the node to remove
 */
void DoublyLinkedList::remove(int index){
    if(index < 0 || index >= size()){
        return;
    }
    
    if(index == 0){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }else if(index == size() - 1){
        pop();
    }else{
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    
}

/**
 * Prints the DoublyLinkedList to the console.
 */
void DoublyLinkedList::print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/**
 * Returns the data stored in the node at the specified index.
 * 
 * @param index The index of the node to return
 * @return int& Reference to the data stored in the node
 */
int& DoublyLinkedList::at(int index){
    if(index < 0 || index >= size()){
        throw "Index out of bounds";
    }
    
    Node* temp = head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    
    return temp->data;
}