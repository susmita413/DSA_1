#include<iostream>
using namespace std;


class SLL{
     class node{
     public:
        int data;
        node* next;
        node(int data){
          this->data = data;
          this->next = nullptr;
        }
     };
     node* top ;
     public:
     SLL(){
     this->top = nullptr;
     }


     bool isEmpty(){
          if(top == nullptr){
            return true ;
          }
          else{
               return false ;
          }
       
     }

     void push(int data){
          node* newNode = new node(data);
          if(isEmpty()){
              top = newNode ;
              return;
          }
          else{
               newNode->next = top ;
               top = newNode ;
               return;
          }
     }

     void pop(){
          if(isEmpty()){
               cout << "stack underflow\n" ; return;
          }
          node* del = top ;
          top = top->next;
          delete del;
     }

     void peek(){
          if(isEmpty()){
               cout<< "stack empty\n" ;
          }
          else{
               cout << " topmost number: " << top->data << endl ;
          }
     }

     void display(){
          if(isEmpty()){
               cout<< "stack empty. what do you expect?\n" ; return;
          }
          node* cur = top ;
          while(cur != nullptr){
               cout << cur->data << endl ;
               cur= cur->next ;
          }
          cout<< endl ;
     }
     
};

int main(){
     SLL list;
     list.push(1);
     list.push(2);
     list.push(3);
     list.push(4);
     list.display();
     list.peek();

     list.pop(); //4
     list.display();
     list.peek();

     list.pop(); //3
     list.display();
     list.peek();

     list.pop();  //2
     list.display();
     list.peek();

     list.pop();  //1
     list.display();
     list.peek();

     list.pop();
     list.display();
     list.peek();
}