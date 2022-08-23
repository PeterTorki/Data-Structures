//
// Created by peter on ٢٨‏/١٢‏/٢٠٢١.
//
#include <bits/stdc++.h>
#include "Stack_w_list.h"
using namespace std;
int main(){
    Stack s1;
    s1.push(10);
    s1.push(50);
    s1.push(465465);
    s1.display();
    cout<<"\n";
    cout<<s1.get_top()<<"\n";
    s1.pop();
    s1.display();
    return  0;
}