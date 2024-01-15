// Delete middle element of a stack

#include <iostream>
using namespace std;

#define size 6
int stack_arr[size];
int top = -1;

bool isFull(){
    if(top+1 == size){
        return true;
    } else{
        return false;
    }
}

bool isEmpty(){
    if(top ==-1){
        return true;
    } else{
        return false;
    }
}

void push(int data)
{
    if (isFull()){
        cout << "Stack Overflow"<< endl;
        return; 
    }

    else{
        stack_arr[top+1] = data;
        top = top + 1;
    }
    
}

int pop() {
    int del;
    if (isEmpty()) {
        cout<<"Stack underflow";
        return 0 ;
    }

    else{
        del = stack_arr[top];
        top = top - 1;
        return del ;

    }
    
}

void deletemid(){
    int mid = top/2 ;
    for(int i= mid; i<=top; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    top= top-1;
}

void printstack(){

    int i;
    if(isEmpty()){
        cout<< "empty string";
    }
    else{
        for(i=top ; i>=0; i--){
            cout<< stack_arr[i] << " ";
        }
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    //push(60);

    printstack();
    cout << "\n after deleting mid element: " ;

    deletemid();

    printstack();

}