//
// Created by peter on ٢٨‏/١٢‏/٢٠٢١.
//
#include <bits/stdc++.h>
#include "BSTree.h"
using namespace std;
int main(){
    BST tree, *root = nullptr;
    root = tree.insert(root, 20);
    tree.insert(root, 7586);
    tree.insert(root, 1);
    tree.insert(root, 58);
    tree.insert(root, 5);
    tree.insert(root, -100);
    tree.insert(root, 23);
    tree.print_inc(root);
    cout<<"\n";
    tree.print_dic(root);
    cout <<"\n";
    cout << (tree.find(root, 300) ? "Found\n": "Not Found\n");
    cout << tree.Maximum(root) -> data<<" "<<tree.Minimum(root) -> data<<"\n";
    tree.remove(root, -100);
    tree.print_inc(root);
}