/*
coded by He Zhu 
2018 Nov 06
*/
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include<iostream>


template <class T>
class Node{
public:
    T data ;
    Node *next = NULL;
};

template <class T>
class LinkedList{
private:
    Node<T> *head;
    Node<T> *tail;
    int length;
public :
    //constructors
    LinkedList();
    ~LinkedList();

    //methods
    void push_front(T new_data);
    void push_end(T new_data);
    T peek_front();
    T peek_end();
    void insert_after(T old_data, T new_data);
    bool isEmpty();
    T* to_array();
    void print();
    int get_length();
};

//constructor
template <class T>
LinkedList<T>::LinkedList(){
    this->head=NULL;
    this->length=0;
    this->tail=NULL;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList(){
    std::cout<<"The LinkedList is destroyed";
}

//push method
template <class T>
void LinkedList<T>::push_front(T new_data){
    Node<T> *node = new Node<T>();
    node->data  = new_data;
    if(length == 0 )
    {
        this->head = node;
        this->tail = node;    
    }
    else
    {
        node->next = this->head;
        this->head = node;
    }
    length++;
}

//push end
template <class T>
void LinkedList<T>::push_end(T new_data){
   Node<T> *node = new Node<T>();
    node->data  = new_data;

    if(length == 0 )
    {
        this->head = node;
        this->tail = node;    
    }
    else
    {
        this->tail->next = node;
        this->tail = node;
    }
    length++;
}

//peek end
template<class T>
T LinkedList<T>::peek_end(){
    return this->tail->data;
}

//peek first
template<class T>
T LinkedList<T>::peek_front(){
   return this->head->data;
}

//isEmpty
template<class T>
bool LinkedList<T>::isEmpty(){
    if(length==0)
        return true;
    else
        return false;
}

//print
template<class T>
void LinkedList<T>::print(){
    Node<T> *node = new Node<T>();
    node = this->head;
    for ( int i = 0 ; i < this->length ; i ++ ){
        std::cout<<node->data<<" ";
        node = node->next;
    }
    std::cout<<"\n";
}

//insert
template <class T>
void LinkedList<T>::insert_after(T old_data,T new_data){
    Node<T> *node = new Node<T>(); 
    node = this->head;
    while ( node != NULL ){
     if(node->data == old_data)
        {   
        //create a new node
        Node<T> *new_node = new Node<T>();
        //assign new value to this new node
        new_node->data=new_data;
        //assign next node to new node
        new_node->next = node->next;
        //assgin new node as the next of old node
        node->next = new_node;
        this->length++;
        break;
        }
        node = node->next;
    }
}

template <class T>
T* LinkedList<T>::to_array(){
    T *numbers = new T[length];
    Node<T>* node = new Node<T>();
    node = this->head;
    for ( int i = 0 ; i < length ; i ++ ){
        numbers[i] = node->data;
        node = node->next;
    }
    return numbers;
}

template<class T>
int LinkedList<T>::get_length(){
    return length;
}

#endif
