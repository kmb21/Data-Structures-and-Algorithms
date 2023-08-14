/*
    Copyright (c) 2023
    Maxwell Kumbong

    This is the main file to tesst the array class
*/
#include <iostream>
#include "ArrayList-main.hpp"
using namespace std;

int main(){
    //create an empty array of size 15 and type int
    ArrayList<int> testArray(20);
    for (int i = 0; i < 20; i++){
        testArray.insertLast(i);
    }
    cout << testArray.get(7) << endl;
    
    return 1;

}