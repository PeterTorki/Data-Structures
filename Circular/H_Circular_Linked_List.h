#include <bits/stdc++.h>
#ifndef DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H
#define DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H
using namespace std;
class Node{
public:
    int data;
    Node *Next;
};
class circular_List{
    Node *Head;
public:
    circular_List();
    void add_to_Head(int u_data);
    void Print();

    void add_to_tail(int u_data);

    void delete_from_Head();

    void delete_from_tail();
};
circular_List::circular_List()
{
    Head = NULL;
}
void circular_List :: add_to_Head(int u_data){
    Node *newNode = new Node;
    newNode -> data = u_data;
    if(Head == NULL) {
        Head = newNode;
        newNode -> Next  = Head;
    }
    else{
        Node *Temp = Head;
        while(Temp -> Next != Head)
            Temp = Temp -> Next;

        Temp -> Next = newNode;
        newNode -> Next = Head;
        Head = newNode;
    }
}
void circular_List :: Print()
{
    cout<<Head -> data<<" ";
    Node *Temp = Head -> Next;
    while (Temp != Head)
    {
        cout<< Temp -> data<<" ";
        Temp = Temp -> Next;
    }
}
void circular_List::add_to_tail(int u_data)
{
    Node *newNode = new Node;
    newNode -> data = u_data;
    newNode -> Next = NULL;
    if(Head == NULL) {
        Head = newNode;
        Head = Head -> Next;
    }
    else {
        Node *temp = Head;
        while (temp -> Next != Head)
            temp = temp->Next;

        newNode -> Next = Head;
        temp->Next = newNode;
    }
}
void circular_List :: delete_from_Head(){
    if(Head == NULL)
        cout<<"THE Head IS already EMPTY";
    else if(Head -> Next == Head){
        delete Head;
        Head == NULL;
    }
    else{
        Node *temp1 = Head , *temp2 = Head;
        while (temp1 -> Next != Head)
            temp1 = temp1 -> Next;

        Head = Head -> Next;
        temp1 -> Next = Head;
        delete temp2;
    }
}
void circular_List :: delete_from_tail() {
    if(Head == NULL)
        cout<<"THE Head IS already EMPTY";
    else if(Head -> Next == Head){
        delete Head;
        Head == NULL;
    }
    else
    {
        Node *temp1 = Head;
        Node *temp2 = NULL;
        while (temp1 -> Next != Head) {
            temp2 = temp1;
            temp1 = temp1 -> Next;
        }
        delete temp1;
        temp2 -> Next = Head;
    }
}

#endif //DATA_STRUCTURE_CIRCULAR_LINKED_LIST_H
