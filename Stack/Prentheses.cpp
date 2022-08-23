//
// Created by peter on ٢٨‏/١٢‏/٢٠٢١.
//
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    char data;
    Node* next;
};
class Stack{
    Node* top;
public:
    Stack(){
        top = nullptr;
    }
    void push(char num){
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
    char get_top(){
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

bool are_pair(char op, char cl){
    if(op == '(' && cl == ')')
        return true;
    else if(op == '{' && cl == '}')
        return true;
    else if(op == '[' && cl == ']')
        return true;
    return false;
}
bool check_balanced(string exp){
    Stack s1;
    for(int i = 0 ; i < exp.size() ;i++){
        if(exp[i] == '(' ||exp[i] == '{' || exp[i] == '[' ) {
            s1.push(exp[i]);
        }
        else if(exp[i] == ')' ||exp[i] == '}' || exp[i] == ']'){
            if(s1.is_empty() || !are_pair(s1.get_top(), exp[i])) {
                return false;
            }
            else s1.pop();
        }
    }
    s1.display();
    return  s1.is_empty();
}
float Mat_ope(float op1, float op2, char operate){
    switch (operate) {
        case '+':
            return op1 + op2;
            break;
        case '-':
            return op1 - op2;
            break;
        case '*':
            return op1 * op2;
            break;
        case '/':
            return op1 / op2;
            break;
    }
    return 0;
}
float EXP_eval(string exp){
    stack<float>stc;
    for(int i = 0 ; i < exp.size() ; i++){
        if(isdigit(exp[i]))       stc.push(exp[i] - '0');
        else{
            float op2 = stc.top();
            stc.pop();
            float op1 = stc.top();
            stc.pop();
            float result = Mat_ope(op1, op2, exp[i]);
            stc.push(result);
        }
    }
    return stc.top();
}
int main(){
    string s;
    //cin >> s;
   // cout <<( check_balanced(s) ? "Balanced": "Not Balanced");
    cout << EXP_eval("382/+5-");
}