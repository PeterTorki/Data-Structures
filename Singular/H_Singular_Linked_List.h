
#include <bits/stdc++.h>
#ifndef DATA_STRUCTURE_LISTED_H
#define DATA_STRUCTURE_LISTED_H
using namespace std;
class Node{
public:
    int data;
    Node *Next;
};

class List{
    Node *Head, *Tail;
public:
    List();

    ~List();

    void add_to_tail(int data);

    void Print();

    int Count();

    bool Is_empty();

    void add_to_head(int data);

    int delete_from_head();

    int delete_from_tail();

    int Minumum_in_List();

    int get_Odd_Sum();

    void addSecond(int x);

    void deleteSecond();

    int findNode(int x);

    void delete_list();

    Node *copy_List();

    void delete_with_key(int key);
};


List::List(){
    Head = Tail = NULL;
}

List::~List()
{
    Node *temp1 = Head, *temp2=NULL;
    while(temp1 != NULL)
    {
        temp2 = temp1 -> Next;
        delete temp1;
        temp1 = temp2;
    }
}
void List::add_to_head(int data){
    Node *newNode = new Node;
    newNode -> data = data;
    newNode -> Next = NULL;

    if(Head == NULL)
        Head = Tail = newNode;

    else
        newNode -> Next = Head, Head = newNode;
}

int x;
int List::delete_from_head()
{
    if(Head == NULL)
    {
        cout<<"List is Empty\n";
        return 0;
    }

    else if (Head -> Next == NULL) {
        // x = Head -> data;
        delete Head; // 1) after deleting the Node Address of head is still reserved
        Head = NULL; // 2) We did this <-
        return  x;
    }

    else
    {                               //| |
        Node *temp = Head;          //5 6 7
        Head = Head-> Next;
        //x = temp -> data;
        delete temp;
        temp = NULL;
        return  x;
    }
}

int List :: Minumum_in_List()
{
    Node *temp = Head;
    int minm = INT_MAX;
    while(temp != NULL) {
        minm = min(minm, temp->data);
        temp = temp->Next;
    }
    return  minm;
}

int List :: get_Odd_Sum(){
    Node *temp = Head;
    int sum_odd = 0;
    while(temp != NULL)
    {
        if(temp -> data % 2)
            sum_odd += temp -> data;

        temp = temp -> Next;
    }
    return  sum_odd;
}
void List::add_to_tail(int data){
    Node *newNode = new Node;
    newNode -> data = data;
    newNode -> Next = NULL;

    if(Head == NULL)
        Head = Tail = newNode;

    else{                                              //T
        Node *temp = Head;               //              TE
        while(temp -> Next != NULL)     //5 -> 6 -> 4 -> 88
            temp=temp->Next;

        temp -> Next = newNode;
        Tail = newNode;
    }
}

int List::delete_from_tail()
{
    if(Head == NULL)
    {
        cout<<"List is Empty\n";
        return 0;
    }
    else if(Head -> Next == NULL)
    {
        //  x = Head -> data ;
        delete Head;
        Head = NULL;
        return  x;                          // |
    }                                       // |
    else{                                   // 5 - > 6 -> 7 ->9
        Node *temp1 = Head, *temp2 =NULL;
        while(temp1 -> Next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1 -> Next;
        }
        x = temp1 ->data;
        delete temp1;
        Tail = temp2;
        Tail -> Next = NULL;
        return x;
    }
}

void List::addSecond (int x)
{
    Node *newNode = new Node;
    newNode -> data = x;
    if(Head == NULL)
    {
        return;
    }
    newNode -> Next = Head -> Next;
    Head -> Next = newNode;
}

void List :: deleteSecond ()
{
    Node *temp = Head ->Next;
    if (Head == NULL) {
        cout<<"List is Empty\n";
        return;
    }
    else {
        Head -> Next = temp->Next;
    }
}

int List:: findNode (int x)
{
    int n = 1;
    Node *temp = Head;      //      |
    while (temp != NULL)    // 5 -> 6 -> 7 -> 9
    {
        if(temp -> data == x)
            return  n;

        temp = temp -> Next, n++;
    }
    return -1;

}
void List::Print(){
    Node *temp = Head;
    while(temp!=NULL) {
        cout<<temp -> data<<" ";
        temp = temp -> Next;
    }
}
int List::Count()
{
    Node *temp = Head;
    int cnt = 0;
    while(temp != NULL)
        cnt++ ,temp = temp -> Next;

    return cnt;
}
bool List::Is_empty()
{
    return Head == NULL;
}
void List :: delete_with_key(int key){
    if(Head == nullptr)
       cout<<"EMPTY";

    else{
        Node* cur = Head;
        Node * temp = new Node;
        while(cur -> Next != nullptr){
            if(cur -> Next -> data == key){
                temp = cur -> Next;
                cur -> Next = temp -> Next;
                delete temp;
            }
            else
                cur = cur -> Next;
        }
        if(Head -> data == key) {
            temp = Head;
            Head = Head->Next;
            delete temp;
        }
    }

}
Node* List :: copy_List(){
    Node *Temp = Head;

    Node *Head2 = new Node;
    Head2 -> Next = nullptr;
    Head2 -> data = Temp -> data;
    Temp = Temp -> Next;

    Node *mover = Head2;

    while(Temp != nullptr){
        mover -> Next = new Node;
        mover = mover -> Next;
        mover -> data = Temp -> data;
        Temp  = Temp -> Next;
    }
    mover -> Next = nullptr;
    return Head2;
}
#endif //DATA_STRUCTURE_LISTED_H