#pragma once

class smartArray{
private:

    int size; //  current array's member count
    int *array; //define memory for array
    int capacity; // capacity increases volume of the array to not use new dynamic memory
public:
    //default constructor creates an array with capacity 10
    smartArray();
    //show array's members
    void showArray();
    //push an element in the array's end
    void push_back(int value);
    // makes new array with more space for new element
    void moreCapacity();

    // get an element from array by index
    int getElementByIndex(int index);
    //how much elemenents does array have
    int getSize();

    // add in the array an element [value] in position [index]
    void insertElement(int index, int value);
    //destructor frees dynamic memory of the array
    ~smartArray();
};
