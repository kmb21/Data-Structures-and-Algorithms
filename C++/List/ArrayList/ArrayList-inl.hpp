/*
    Copyright (c) 2023
    Maxwell Kumbong

    This file contains the definition of the ArrayList Class. 
    The ArrayList class inherits from the virtual listADT class.

*/
#pragma once
#include "ListADT/List.hpp"

template <typename T>


class ArrayList : public List<T> {
    private:
        int size;   // Size of arraylist
        int capacity;
        int partition(int start, int end);
        void resize();  // Resize function to increase capacity if needed
        T *array; //array pointer
        // bool checkInvariants(); //Function checks if the size of an array is less than its capacity
    public:

        /**
        *A constructor for the ArrayList class. Is called only when the capacity is specified
        @param cap: An integer specifying the capacity of the Array
        */
        ArrayList(int cap);

        ArrayList(); // Substitute constructor. Gets called if capacity is not specified
        ~ArrayList(); // Class destructor. Gets called when array is to be deleted
        bool isEmpty(); // Returns true if array is empty. Otherwise, false
        int getSize(); // Returns size of array
        

        /**
        *Returns the value stored at a specific index in an array. Otherwise, throws and error
        @param index: A value of type of array
        */
        T get(int index);

        T getFirst(); // returns first value in the array
        T getLast(); // returns last value in the array

        /**
        *Inserts val at the front of array and increments size
        @param val: data of type of array
        */
        void insertFirst(T val); 
        
        /**
        *Inserts val at the back of array and increments size
        @param val: data of type of array
        */
        void insertLast(T val);
        void quickSort(int start, int end);
        T removeFirst(); // removes and returns the first value in the array
        T removeLast(); // removes and returns the last value in the array
        T remove(int index); // removes and returns value at index
        void Sort(); // Sorts the array in place or returns a sorted array
        void reverse(); // reverses the array or returns a sorted array
};