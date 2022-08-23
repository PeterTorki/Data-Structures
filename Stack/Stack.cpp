#include <bits/stdc++.h>
#include "Stack.h"
int main(){
    Stack s1;
    s1.Push(55);
    s1.Push(46346);
    s1.Print();
    s1.Push(46399646);
    s1.Push(58755);
    s1.Push(46);
    s1.Print();
    cout<<s1.Top_element();
    s1.Pop();
    s1.Push(46);
    return  0;
}