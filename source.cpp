#include <cstdint>
#include<iostream>
#include <string>
#include"smart_array.h"

using namespace std;

int main()
{
    Smart_array my_first_array;
    bool is_exit = false; //using it for exit from menu ()
    while(!is_exit) // tested standart constructor , push_back() and show_array();
    {   cout << "___________________"<<endl;
        cout<< endl << "___________MENU_________________" << endl;
        cout<<"1 : test push_back | 2 : test pop_back | 3 :test show_array \n 4 : show last element 5 : instert an element \n 0 : for exit "<<endl;
        int userChoose;
        cout<<"\nYour Choise ->";
        cin>>userChoose;
        int tempValue; //for user inputed values
        int index;// index for insert function
        // SIMPLE TEST MENU
        switch (userChoose)
        {

            case 1:
                cout<<"\n push back >";
                cin>>tempValue;
                my_first_array.push_back(tempValue);
                break;
            case 2:
                my_first_array.pop_back();
                break;
            case 3:
                my_first_array.show_array();
                break;
            case 4:
                cout<<my_first_array.return_last();
            case 5:
                cout<<"\nWrite value to add in array->";
                cin>>tempValue;
                cout<<"\n write index to put in the array->";
                cin>>index;
                my_first_array.insert(tempValue,index);
                break;
            case 0:
                is_exit=true;
                break;
            default:
                break;
                }
        }
      Smart_array second_array;
      second_array=my_first_array;
      second_array.show_array();
      //test checking of [] owerloading
      cout<<"the second array's 3 member " <<second_array[3];
}
