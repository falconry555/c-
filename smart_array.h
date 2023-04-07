#pragma once

#include <cstdio>
class Smart_array
{
private:
    int size; // size is the index of the last member
    int capacity; //reserved memory
    int *array;
public:
    //default constructor creates an array with starting capacity 10 members
    Smart_array();

    //copy constructor
    Smart_array( Smart_array  &other);


    //func-n returns the last element of array
    int return_last();

    //function increases capacity if array's  factic size aproximetly==capaticy
    void more_capacity();

    //method shows all array's members
    void show_array();

    //fill array with random numbers in range 0:100
    void fill_random();

    //insert an element value in position index

    void insert(int value, int index);

    //add element value in the end of array

    void push_back(int value);

    //delete an element from arrays back
    void pop_back();

    //return array's factic size'

    int get_size();

    //get elelement by index -> index

    int get_by_index(int index);
    // operator[] overloading to work with array by index


    // = operator  overloading for copy array

   Smart_array &operator = ( Smart_array &other)
   {

        this->size=other.get_size();
        more_capacity();
        if(this->array!=nullptr)
        {
            delete [] array;

        }
        this->array=new int[size];
        for(int i=0;i<size;i++)
        {
            array[i]=other.get_by_index(i);
        }
        return *this;

    }

  //overload [] to get elelement by []
  int & operator [](const int index);

    //constructor clear  dynamic memory
    ~Smart_array();
};
