#include <bits/stdc++.h>
#include "H_Circular_Linked_List.h"
using namespace std;
int main()
{
    circular_List s1;
    s1.add_to_Head(154);
    s1.add_to_Head(3256);
    s1.add_to_Head(465476463);
    s1.add_to_tail(5465);
    s1.add_to_Head(564);
    s1.add_to_tail(547);
    s1.add_to_tail(4);
    s1.delete_from_Head();
    s1.delete_from_tail();
    s1.Print();
}