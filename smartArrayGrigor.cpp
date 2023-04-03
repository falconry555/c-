#include<iostream>
#include<string>
using namespace std;
// class makes adynamic  array
class smartArray
{
    int *arr ;
    int size;


public:
    //constructor works with data inputed by user
    smartArray(int size )
    {
//fill  array with random numbers 0:100
        this->size=size;
        cout<<" creating an array with " <<size <<" size"<<endl<<" elements by default will be initializated 0"<<endl;
        this->arr=new int[size];
        for(int i=0 ;i< size ;i ++)
        {

            cout<<*(arr+i)<<"___";

        }
    }
    void fillArrayRandom()
    {
//shows all array's elements
        cout<<"_______________________"<<endl;
        cout<<" array will fill by random numbers in range 0;100\n\n";
        srand(time(NULL));
        for(int i=0;i<this->size;i++)
        {

            *(arr+i)=rand()% 100;

        }
    }
    void showArray()
        {
 //gets an element by user imputed index

            for(int i=0;i<size;i++)
            {

                cout<<*(arr+i)<<"___";

            }
        }
    int getElementByIndex(int userChoosedIndex)
    {


            int resultVale;

                resultVale=arr[userChoosedIndex];

                return resultVale;
            }




int getSize()
    {
        return this->size;
    }

        ~smartArray(){

        delete [] arr;
        cout<<"\nDESTRUCTOR:\nmemory deleted";
        }

};
int main()
{   cout<<" Write the array size, what you whant to create \n ARRAY SIZE->";
    int userArraySize;
    cin>> userArraySize;

    smartArray myFirstArray(userArraySize);
    myFirstArray.fillArrayRandom();
    myFirstArray.showArray();
    cout<<"n>you can show an element of the created array\n> write element index betwen 0 : "<<userArraySize-1<<endl;
    cout<<">your choose -> ";
    int get_Element_By_Index ;
    cin>>get_Element_By_Index;
    //if userInputed value more than arrays index
    try{
        cout<<"_ARRSIZE : " <<myFirstArray.getSize();
        if(get_Element_By_Index>myFirstArray.getSize())
           {
               throw " Error :! you cant write index more than array has (MAXVALUE : ";

           }
    }


catch( string &indexError)
           {
                cout<<indexError;
           };

    cout<<"\n____________\n"<<"element index -> " <<get_Element_By_Index<<"\nElement value ->"<<myFirstArray.getElementByIndex(get_Element_By_Index);
}
