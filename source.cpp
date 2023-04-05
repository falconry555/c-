#include "smartArray.h"
#include <iostream>

using namespace std;
int main()
{
    smartArray myFirstArray;
    myFirstArray.push_back(5);
    myFirstArray.push_back(11);
      myFirstArray.push_back(11);
    cout<<endl<<"_______________________\n";
    myFirstArray.getElementByIndex(2);
    cout<<endl<<"_______________________\n";
   cout<< myFirstArray.getSize()<<endl<<endl;
    myFirstArray.showArray();
    cout<<endl;
    myFirstArray.push_back(112);

    myFirstArray.showArray();
     cout<< myFirstArray.getSize()<<endl<<endl;
     myFirstArray.insertElement(2,777);
    cout<<"______"<<myFirstArray.getSize();
}
