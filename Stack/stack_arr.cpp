//
// Created by susmita on 12/6/2023.
//
#include<iostream>
using namespace std;

#define size 4
int stack_arr[size];
int top = -1 ;

bool isFull(){
    if(top == size - 1)
        return true ;
    else
        return false ;
}

bool isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}


void push(int data){
    if(isFull()){
        cout << "stack overflow\n";
    }
    else{
        stack_arr[++top]= data ;
    }
}

void pop(){
    if(isEmpty()){
        cout<< "stack underflow\n" ;
    }
    else{
        stack_arr[top]= 0 ;
        top = top -1 ;
    }
}

void peek(){
    if(isEmpty()){
        cout<< "stack empty\n" ; return ;
    }
    else{
        cout<< "topmost number: " << stack_arr[top] << endl ;
    }
}


void display(){
    cout<< "\nIn stack : " ;
    if(isEmpty()){
        cout<< "stack is empty\n" ;
        return;
    }
    for(int i= top ; i>=0 ; i--){
        cout << stack_arr[i] << " " ;
    }
}

int main(){
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    display();
    cout<< endl ;

    pop();  //50
    display();
    peek();

    pop(); //40
    display();
    peek();

    pop();   //30
    display();
    peek();

    pop();   //20
    display();
    peek();
    cout<< endl ;

    pop();
    display();
    peek();

    return 0;



}