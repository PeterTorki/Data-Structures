//
// Created by peter on ٦‏/١٢‏/٢٠٢١.
//
#include <iostream>
#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H
using namespace std;
class Stack{
private:
    int stackArr[5];
    int top;
public:
    Stack();

    bool is_Empty();

    void Push(int data);

    int Pop();

    int Top_element();

    void Print();

    bool is_Full();
};
Stack::Stack(){
    top = -1;
}
bool Stack::is_Empty(){
    return  top == -1;
}
bool Stack::is_Full(){
    return  top == 4;
}
int Stack::Pop(){
    if(!is_Empty())     return stackArr[top--];
    return cout << "Stack is Empty\n" , 0;
}
void Stack::Push(int data){
    if(!is_Full())     stackArr[++top] = data;
    else        cout<<"Stack Is FUll\n";
}
int Stack::Top_element(){
    return stackArr[top];
}
void Stack::Print(){
    if(is_Empty())      {cout<<"Stack is Empty "; return;}
    for (int i = top; i >= 0 ; i--)
        cout << stackArr[i] <<" ";
    cout<<"\n";
}
#endif //DATA_STRUCTURE_STACK_H
