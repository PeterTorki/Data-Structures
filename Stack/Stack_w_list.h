//
// Created by peter on ٢٨‏/١٢‏/٢٠٢١.
//
#include <bits/stdc++.h>
#ifndef DATA_STRUCTURE_STACK_W_LIST_H
#define DATA_STRUCTURE_STACK_W_LIST_H
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
class Stack{
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    void push(int num){
        Node *newItem = new Node;
        newItem -> data = num;
        newItem -> next = top;
        top = newItem;
    }
    bool  is_empty(){
        return top == nullptr;
    }
    void pop(){
        if(is_empty())
            cout <<"Stack is empty";
        else{
            Node* temp = top;
            top = top -> next;
            temp = temp -> next = nullptr;
            delete temp;
        }
    }
    int get_top(){
        if(is_empty())
            cout <<"Stack is empty";
        else{
            return top -> data;
        }
    }
    void display(){
        Node *temp = top;
        while (temp != nullptr){
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }
};
#endif //DATA_STRUCTURE_STACK_W_LIST_H
