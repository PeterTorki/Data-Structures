//
// Created by peter on ١٤‏/١١‏/٢٠٢١.
//
#include <iostream>
#ifndef DATA_STRUCTURE_H_DOUBLY_LINKED_H
using namespace std;
class Node{
public:
    int data;
    Node *Next;
    Node * Prev;
};

class List{
    Node *Head;
public:
    List();

    void add_to_head(int u_data);

    void add_to_tail(int u_data);

    void Print();

    void delete_from_Head();

    void delete_from_Tail();

    Node* copy_List();

    void Print(Node *Head);

    int ret_data();
};
List :: List(){
    Head = nullptr;
}
void List ::add_to_head(int u_data){
    Node *newNode = new Node;

    newNode -> data = u_data;
    newNode -> Next = nullptr;
    newNode -> Prev = nullptr;

    if(Head == nullptr) {
        Head = newNode;
    }

    else{
        newNode -> Next = Head;
        Head -> Prev = newNode;
        Head = newNode;
    }
}

void List :: add_to_tail(int u_data){
    Node* newNode = new Node;
    newNode -> data = u_data;
    newNode -> Next = nullptr;
    newNode -> Prev = nullptr;
    if(Head == nullptr)
        Head = newNode;
    else
    {
        Node* Temp = Head;
        while(Temp -> Next != nullptr)
            Temp = Temp -> Next;

        Temp -> Next = newNode;
        newNode -> Prev = Temp;
    }
}
void List ::Print(){
    Node* Temp = Head;
    while(Temp != nullptr) {
        cout << Temp->data << " ";
        Temp = Temp -> Next;
    }
}

void List ::Print(Node *Head){
    Node* Temp = Head;
    while(Temp != nullptr) {
        cout << Temp->data << " ";
        Temp = Temp -> Next;
    }
}

void List ::delete_from_Head(){
    if(Head == nullptr)
        cout<<"List Is empty";

    else if(Head -> Next == nullptr){
        delete Head;
        Head = nullptr;
    }
    else{
        Node* Temp = Head;
        Head = Head -> Next;
        delete Temp;
        Head -> Prev = nullptr;
    }
}
void List ::delete_from_Tail(){
    if(Head == nullptr)
        cout<<"List Is empty";

    else if(Head -> Next == nullptr){
        delete Head;
        Head = nullptr;
    }
    else{
        Node* Temp = Head;
        while (Temp -> Next)
            Temp = Temp -> Next;

        Temp -> Prev -> Next = nullptr;
        delete Temp;
    }
}

#endif //DATA_STRUCTURE_H_DOUBLY_LINKED_H
