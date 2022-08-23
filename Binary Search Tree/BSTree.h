//
// Created by peter on ٢٨‏/١٢‏/٢٠٢١.
//
#include <bits/stdc++.h>
#define nullptr NULL
#ifndef DATA_STRUCTURE_BSTREE_H
#define DATA_STRUCTURE_BSTREE_H
using namespace std;
class BST{
public:
    int data;
    BST *left, *right;
    BST();
    BST(int num);
    BST *insert(BST *root, int num);

    void print_inc(BST* root);

    void print_dic(BST* root);

    BST* find(BST *root, int num);


    BST *Maximum(BST *root);

    BST *Minimum(BST *root);

    BST *remove(BST *root, int num);

    bool is_leaf(BST *root);
};
BST :: BST(){
    data = 0;
    right = left = nullptr;
}
BST :: BST(int num){
    data = num;
    right = left = nullptr;
}
BST* BST::insert(BST* root, int num){
    if(!root) return new BST(num);
    if(num > root -> data)  root -> right = insert(root -> right, num);
    else                    root -> left = insert(root -> left, num);
    return  root;
}
void BST:: print_inc(BST* root){
    if(!root)   return;
    print_inc(root -> left);
        cout << root ->data<<" ";
    print_inc(root -> right);
}
void BST:: print_dic(BST* root){
    if(!root)   return;
    print_dic(root -> right);
    cout << root -> data<<" ";
    print_dic(root -> left);
}
BST* BST::find(BST* root, int num){
    if(!root)  return NULL;
    else if( num == root -> data ) return root;
    else if(num > root -> data) find(root -> right, num);
    else return find(root -> left, num);
}
BST* BST :: Maximum(BST* root){
    while (root -> right )
        root = root -> right;
    return root;
}
BST* BST :: Minimum(BST* root){
    while (root -> left )
        root = root -> left;
    return root;
}
BST* BST :: remove(BST* root, int num){
    if(!root)   return root;
    else if(root -> data < num) root -> right = remove(root -> right, num);
    else if(root -> data > num) root -> left =  remove(root -> left, num);
    else{
        if(root -> left == nullptr){
            BST* temp = root -> right;
            delete root;
            return temp;
        }
        else if(root -> right == nullptr){
            BST* temp = root -> left;
            delete root;
            return temp;
        }
        else{
            BST* temp = Minimum(root -> right);
            root -> data = temp -> data;
             remove(root -> right, temp -> data);
        }
    }
    return root;
}
bool BST :: is_leaf(BST* root){
    return (root && !(root -> left) && !(root -> right));
}
#endif //DATA_STRUCTURE_BSTREE_H