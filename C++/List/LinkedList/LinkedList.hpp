#pragma once
#include "ListADT/List.hpp"


template <typename T>
class ListNode : public List<T> {
    private:
        int size;
        ListNode<T> *head;
        ListNode<T> *tail;
        
    public:
        /**
         * The listnode constructor for the linkedlist. If the user does not specify the value, the value
         becomes 0 and the next point is a nullptr
         * @param val: The value of the listnode
         * @param next: A pointer to the next node in the list
        */
        ListNode(T val, ListNode<T> *next);
        /**
         * The destructor for the linked list class
        */
        ~ListNode();

        ListNode<T> *next;
        
        bool isEmpty(); // O(1) returns if the list is empty or not
        int getSize(); // O(1) returns the size of the linked list
        T getFirst(); // O(1) Returns the first value of the linked list
        T getLast(); // O(1) returns the last value of the linked list

        /**
         * O(1)
         * Inserts a node at the start of the list
         * @param val: The value of the node to be inserted
        */
        void insertFirst(T val); 


        /**
         * O(n) because we have to find the node before the last node
         * Inserts a node at the end of the list
         * @param val: The value of the node to be inserted
        */
        void insertLast(T val);

        /**
         * Returns if the linked list contains a node with val
         * @param val: The value of the node we are searching for
        */
        T contains(T val);

        T removeFirst(); // O(1) removes and returns the value of the first node in the list, else an error if empty
        T removeLast(); // O(n) removes and returns the value of the last node in the linked list, else an error
        T remove(T val); // O(n) removes and returns the value of the node with the value 

        void sort(); //O(nlogn)
        void reverse(); // O(n)
} ;

