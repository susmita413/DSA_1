//  // susmita
#include<iostream>
using namespace std;

class tree{
     class node{
          public:
          node* left;
          int data ;
          node* right ;
          node(int data){
               this->left = nullptr ;
               this->data = data ;
               this->right = nullptr ;
          }
     };
     public:
     node* root ;
     tree(){
          this->root = nullptr ;
     }

     node* create(int data){
        // cout<< "enter data (-1 for no data) : " ; 
         node* newNode = new node (data);
         
     }
};