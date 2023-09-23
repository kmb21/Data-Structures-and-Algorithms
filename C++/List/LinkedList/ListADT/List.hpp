/*
    Copyright (c) 2023
    Maxwell Kumbong


    This is the virtual class for the list ADT.
    Summary of methods: 
        *   getSize(): Returns the size of the list implementation
        *   get(): If key is given, returns value of key. 
                                           If index, returns the value stored at that index
                                           If not specified, returns a random value
        *   getFirst(): Returns first value in list
        *   getLast(): Returns last value in list
        *   insertFirst(val): Inserts val at front of list
        *   insertLast(val): Inserts val at the back of list
        *   removeFirst(): Removes and returns first value in list
        *   removeLast(): Removes and returns last value in list
        *   remove(<Optional: key or index>): If key is given, removes and returns value of key. 
                                            If index, removes and returns the value stored at that index
                                            If not specified, removes and returns a random value
        *   isEmpty(): Returns a boolean value describing if the list is empty or not
        *   
                                        
        *   sort(): Sorts the list in place or returns a sorted list
        *   reverse(): Reverses the list in place or returns a reversed list

*/

template <typename T>
class List {
    public:
    // Virtual functions to be implemented by child classes
        virtual ~List(){};
        virtual int getSize() = 0;
        virtual T getFirst() = 0;
        virtual T getLast() = 0;
        virtual void insertFirst(T val) = 0;
        virtual void insertLast(T val) = 0;
        virtual bool isEmpty() = 0;
        virtual T removeFirst() = 0;
        virtual T removeLast() = 0;
        virtual T remove() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
};

