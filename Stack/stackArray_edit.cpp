// Stack code in C++ //  //
//
#include<iostream>
using namespace std;

#define size 3
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
        stack_arr[top] = NULL ;
        top = top - 1;
        return del ;
    }
    
}

int peek(){
    if(isEmpty()){
        cout<<"Stack UnderFlow\n";
        return 0;
    }
    return stack_arr[top];
}

void printStack()
{
    int i;
    if(isEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return;
    }
    for(i=top; i>=0; i--)
    {
        cout<<stack_arr[i]<<" ";
    }
}

int main(){
    int choice,data;
    while(1){
        cout<<"\n";
        cout<<"1. Push\n"; cout<<"2. Pop\n";
        cout<<"3. Print the top element\n";
        cout<<"4. Print all the elements of the stack\n";
        cout<<"5. Quit\n";
        cout<<" enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter the element to be pushed: "; cin>>data;
                push(data);
                break;
            case 2:
                data = pop();
                if(data != 0){
                    cout<<"Deleted element is " << data << endl;
                }
                break;

            case 3:
                cout<<"The topmost element of the stack is " << peek() << endl;
                break;
            case 4:
                printStack();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Wrong choice\n";

        }
    }

    return 0;
}