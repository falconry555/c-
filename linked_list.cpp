#include"linked_list.h"
#include<cassert>
#include<iostream>
 Node::Node(int data) //standart constructor creates a node with input data
    {
    this->data=data;
    this->nextPtr=nullptr; //last  element of the List shows to nullptr
    }


//standart constructor creates an empty list


 List::List()
 {

    this->head=this->tail=nullptr;// creates
 }
//push_back adds value to the and of the List



void List:: push_back(int value)
{
    Node *temp_node=new Node(value);
    if(head==nullptr)
        head=temp_node; //if there are no elements, temp_node becomes the first element
    if(tail!=nullptr) //if tail is not the first
        tail->nextPtr=temp_node; //if tail is not the  first element , temp_node becomes as tail
    tail=temp_node;
}


//add data to front of the list
void List::push_front(int data)
{
 Node *temp=new Node(data);
 temp->nextPtr=head;
 head=temp;
 if(tail==nullptr) tail=temp;
}
void List::delete_first()
{
    if(head==nullptr) return; // break if list is empty
    if(head==tail) //if in the list only 1 object
    {
        delete tail;
        head=tail=nullptr;
        return;
    }
    //if there are 2 or more elements
    Node *temp=head;
    head=temp->nextPtr;
    delete temp;
}

//delete an element from the end of the array
void List:: pop_back()
{
    if(tail==nullptr) return; // if empty
    if(head==tail) //if only 1 onject
    {
    delete tail;
    head=tail=nullptr;
    return;
    }
    Node *temp=head;
    while(temp->nextPtr!=tail) //find   the alst element
    {
        temp=temp->nextPtr;
    }
    //for(;temp->nextPtr!=tail;temp=temp->nextPtr);//naxaverjin
    temp->nextPtr=nullptr;
    delete tail;
    tail=temp; //temp becomes the last element


}




Node * List:: get_by_index(int index)
{
    Node* element=head; //starting iteration bnodey first element
    assert(index>=0&&"cant get an element by index< 0");
    int counter=0;
    while(element&&counter!=index&& element->nextPtr)
    {
        element=element->nextPtr;
        counter+=1;
    }

    return (counter==index)? element: nullptr;


}
// insert an element with [value]  to the position [index]
void List:: insert(int index,int value)
{
    Node *left=get_by_index(index);
    if(left==NULL) return;
    Node *right=left->nextPtr;
    Node *current=new Node(value);
    left->nextPtr=current;
    current->nextPtr=right;
    if(right==nullptr) //if add in the end
        tail=current;

}

void List:: errase(int index)
{
    if(index<0) return;
    if( index==0)
       { delete_first();} //delete first element
    Node* left=get_by_index(index-1);
    Node *current=left->nextPtr;
    if(current==NULL) return;
    Node *right=current->nextPtr;
    left->nextPtr=right;
    if(current==tail)
        tail=left;
    delete current;
}


int  & List::operator[](int index)
{

    Node *temp=head;
    for(int counter=0;counter!=index;counter++)
    {
        temp=temp->nextPtr;
    }
    return temp->data;
}
List::~List()
{
    while(head!=nullptr) //while list is not empty
    {
        delete_first();
    }
}



