/*
    Copyright (c) 2023
    Maxwell Kumbong

    This is the declaration of the Arraylist class
*/

#include <stdexcept>
#include <typeinfo>
#include "ArrayList-inl.hpp"
using namespace std;


template <typename T>
ArrayList<T> :: ArrayList(int capacity){
    // if (typeid(capacity) == typeid(int)){
    //     throw runtime_error("ArrayList: Capacity must be an integer");
    // }
    this->capacity = capacity;
    this->size = 0;
    this->array = new T[this->capacity];
}


template <typename T>
ArrayList<T> :: ArrayList(){
    // default constructor
    this->capacity = 10;
    this->size = 0;
    this->array = new T[this->capacity];
}

template <typename T>
ArrayList<T> :: ~ArrayList(){
    delete[] this->array;
    this->array = nullptr;
    this->size = 0;
    this->capacity = 0;
}

template <typename T>
bool ArrayList<T> :: isEmpty(){
    return this->size == 0;
}


template <typename T>
int ArrayList<T> :: getSize(){
    return this->size;
}


template <typename T>
T ArrayList<T> :: get(int index){
    if (index >= capacity || index < 0){
        throw runtime_error("ArrayList: Index out of bounds");
    }
    return this->array[index];
}

template <typename T>
T ArrayList<T> :: getFirst(){
    if (this->size == 0){
        throw runtime_error("ArrayList: array is empty");
    }
    return this->array[0];
}


template <typename T>
T ArrayList<T> :: getLast(){
    if (this->size == 0){
        throw runtime_error("ArrayList: array is empty");
    }
    return this->array[this->size-1];
}


template <typename T>
void ArrayList<T> :: insertFirst(T val){
    // check for overflow and resize if necessary
    if (this->size == this->capacity){
        resize();
    }
    for (int i = this->size; i > 0; i--){
        this->array[i] = this->array[i - 1];
    }
    this->array[0] = val;
    this->size++;
}


template <typename T>
void ArrayList<T> :: insertLast(T val){
    // check for overflow and resize if necessary
    if (this->size == this->capacity){
        resize();
    }

    this->array[this->size] = val;
    this->size++;
}


template <typename T>
void ArrayList<T> :: resize(){
    int newCapacity = this->capacity * 2;
    T* tempArray = new T[newCapacity]();
    for (int i = 0; i < this->capacity; i++){
        tempArray[i] = this->array[i];
    }

    delete[] this->array;
    this->array = tempArray;
    this->capacity = newCapacity;


}



template <typename T>
T ArrayList<T> :: removeFirst(){
    // check for overflow and resize if necessary
    if (this->size == 0){
        throw runtime_error("ArrayList: Array is Empty");
    }
    T lastElement = this->array[0];
    for (int i = 0; i > this->size-1; i++){
        this->array[i] = this->array[i + 1];
    }

    this->size--;
    return lastElement;
}


template <typename T>
T ArrayList<T> :: removeLast(){
    // check for overflow and resize if necessary
    if (this->size == 0){
        throw runtime_error("ArrayList: Array is Empty");
    }
    T lastElement = this->array[this->size - 1];
    this->size--;
    return lastElement;

}


template <typename T>
T ArrayList<T> :: remove(int index){
    // check for overflow and resize if necessary
    if (this->size == 0){
        throw runtime_error("ArrayList: Array is Empty");
    }
    else if (index >= this->size || index < 0){
        throw runtime_error("Index Out Of Bounds");
    }
    T elementAtIndex = this->array[index];
    for (int i = index; i < this->size-1; i++){
        this->array[i] = this->array[i + 1];
    }

    this->size--;
    return elementAtIndex;
}



template <typename T>
void ArrayList<T> :: Sort(){
    if (this->size == 0){
        throw runtime_error("ArrayList: Array is Empty");
    }
    int start = 0;
    int end = this->size-1;
    quickSort(start, end);


}
template <typename T>
void ArrayList<T> :: quickSort(int start, int end){
    if ((end > start)){
        int pivotPosition = partition(start , end);
        quickSort(start,pivotPosition-1 );//left side of the array
        quickSort((pivotPosition+1), end);//right side of the array

    }

}

template <typename T>
int ArrayList<T> :: partition(int start, int end){
    int left = start;
    int right= end - 1;
    T pivot = this->array[end];
    while (left <= right){
        if (this->array[left] <= pivot){
            left++;
        }
        else if (this->array[right] >= pivot){
            right--;
        }
        else{
            //swap them and move on to next iteration.
            T temp = this->array[left];
            this->array[left] = this->array[right];
            this->array[right] = temp;
        }        
    }
    T temp = this->array[end];
    this->array[end] = this->array[left];
    this->array[left] = temp;
    return left;


}

template <typename T>
void ArrayList<T>  :: reverse(){
    for (int i = 0; i < this->size/2; i ++){
        T temp = this->array[this->size-i-1];
        this->array[this->size-i-1]= this->array[i];
        this->array[i] =temp;

    }
}