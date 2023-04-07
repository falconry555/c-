#include "smart_array.h"
#include "cassert"
#include <cstddef>
#include <cstdlib>
#include<iostream>
using namespace std;


// default construtor creates integers array with starting size 10 members
Smart_array::Smart_array()
{
    this->size=0;
    this->capacity=5;
    this->array=new int[capacity];
}


//reserving memory if array's size approaching to the capacity
void Smart_array::more_capacity()
{
    if(this->get_size()==this->capacity)
    {this->capacity*=2;
     int *tempArr=new int[this->capacity];
     for(int i=0;i<this->size;i++)
     {
         tempArr[i]=array[i];
    }

    delete []array;
    array=tempArr;}
}

//func-n shows array
void Smart_array::show_array()
{
    cout<<"\n\n Array's members \n\n ______________"<<endl;
    for(int i=0;i<this->size;i++)
    {
        cout<<array[i]<<"__";
    }
    cout<< endl;
}


//returns array's factic size

 int Smart_array :: get_size()
{
    return this->size;
}

//get element by index ->index
int Smart_array:: get_by_index(int index)
{
    assert(index>=0&&index<=this->size&&"error! :  can't get an element out of range!"); //
    return array[index];

}
//returns the last member of the array
int Smart_array::return_last()
{
    return array[size];
}

//add a new member in the array's end
void Smart_array::push_back(int value)
{
    if(this->size==this->capacity)
    {
        more_capacity();
    }
    array[size]=value;
    size+=1;
}

//deleting last element from array
void Smart_array::pop_back()
{

    assert(get_size()>0&&"Error : can't delete members from 0 size array!");
    int *tempArr=new int[this->capacity-1];
    for(int i=0;i<size-1;i++)
    {
        tempArr[i]=array[i];
    }

    this->capacity-=1;
    this->size-=1;
    delete [] array;
    array=tempArr;
}

//insert value in the array by index
void Smart_array::insert(int value, int index)
{
    assert(index<=size&&"error! cant add an element out of range");
    more_capacity();
    int *tempArr=new int[capacity];
    for(int i=0;i<=index-1;i++) //copying till index-1 element of array
    {
        tempArr[i]=array[i];
    }
    tempArr[index]=value;

    cout<< " \n array by index! : "<<array[index]<<endl;
    cout<<endl;
    this->size+=1;
    //copy of the array after added element
    for(int i=size;i>index;i--)
    {
        tempArr[i]=array[i-1];

    }

    delete [] array;
    array=tempArr;

}

//copy constructor

Smart_array:: Smart_array( Smart_array  &other)
    {

        if(array!=nullptr)
        {
            delete []array;
        }

       this->size=other.get_size();
       this->array=new int[size];


        for(int i=0;i<size;i++)
        {
        this->array[i]=other.get_by_index(i);
        }
    }


// overload []  to work with array like an usual cpp array
 int & Smart_array:: operator [](const int index)
 {
     return array[index];
}


//destructor clears the array from dynamic memory
Smart_array::~Smart_array()
{
    delete [] array;
}


