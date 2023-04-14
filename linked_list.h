class Node
{
    public:
    int data; // contains data for this element
    Node *nextPtr; //contains adress of the next element node
    Node(int data); // creates a new element Node with [data]
};


class List{
private:


Node *head,*tail; //head is the first element , tail is the last

public:
//standart constructor creates an empty list
List();
//destructor clear dynamic memory after work
~List();
//delete an element from the end of the array
void pop_back();
// adds an element in the end of the array
void push_back(int value);
// add ann element by value[ data] to the array's start
void push_front(int data);
// delete the first element of array (using in destructor
void delete_first();

void errase(int index);
// get element by index
Node * get_by_index(int index);

//insert value to the position [index]
void  insert(int index,int value);

//returns an element by index[index]
int &operator[] (int index);

};
