// stack using Linked list // Sp //
// 
//
#include <iostream>
using namespace std;

struct list{
    int data;
    struct list* next;
};

typedef struct list node;
node* top = NULL;

void push(int x) {
    node *temp = new node;
   // temp = (node *) malloc(sizeof(node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop( ){
    if(top== nullptr){
        cout<<"stack empty\n";
        return;
    }
    else{
        int del = top->data ;
        node* temp = top;
        top = top->next;
        delete(temp) ;
        cout << "delete element: " << del << endl;
    }
}

void printstack(){
    if(top== nullptr){
        cout<<"stack empty";
    }

    node* temp = top;
    while(temp!= nullptr){
        cout<<temp->data;
        if (temp->next!= nullptr){
            cout<< endl ;
        }
        temp=temp->next;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);

    pop();

    printstack();



}