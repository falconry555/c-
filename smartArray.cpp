#include<iostream>
#include<cassert>
#include "smartArray.h"

using namespace std;

//default construcor creates an array with start capacity 10 members
smartArray::smartArray()
{
    this->size=0;
    this->capacity=10;
    this->array=new int[capacity];
}

//increase  capacity volume for the array
void smartArray::moreCapacity()
{
    this->capacity*=2;
    int *tempArr=new int[capacity];
    for(int i=0;i<this->size;i++)
    {
        tempArr[i]=array[i]; //copying current array in new dynamic array
    }
    delete [] array; // free memory
    array=tempArr; // change default pointer for new array
}

//method adds value in  the  array's back
void smartArray::push_back(int value)
{
    if(this->size==this->capacity)
    {
        moreCapacity();
    }

    array[size]=value;
    size+=1;

}
void smartArray::showArray()
{
    cout<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<"__";
    }
    cout<<endl;
}

int smartArray::getElementByIndex(int index)
{
    assert(0<=index && this->size>=index&&" Error the index is out of range!");
    return array[index];
}

int smartArray:: getSize()
{
    return this->size;
}

//insert element by value in position index
void smartArray::insertElement(int index, int value)
{
    assert(index>=0&&index<=size&&"error, you cant put an elemeent in the posotion");
    if(this->size==this->capacity)
    {
        moreCapacity();
    }
    int *tempArr=new int[capacity];
    //copying array before inputed index
    for(int i=0;i<index;i++)
    {
        tempArr[i]=array[i];
    }
    tempArr[index]=value; //
    //copying mnacac andamner@ tazza masivi mej
    for(int i=(index+1);i<size;i++)
    {
        tempArr[i]=array[size-i];
    }
        delete[] array;
        tempArr=this->array;// pointers offset
}
smartArray::~smartArray()
{
    delete []array;
}


