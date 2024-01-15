// reverse array //

#include <iostream>
using namespace std;

struct list {
    int data;
    struct list* next;
};

typedef struct list node;
node* top = NULL;

void push(int x){
    node* temp ;
    temp= (node*) malloc (sizeof(node));
    temp->data = x ;
    temp->next= top; 
    top = temp ;

}

int pop(){

    if(top== NULL){
        cout << "stack empty" ;
        return 0;
    }
    else{
        int del = top->data ;
        node* temp = top;
        top = top->next ;
        delete( temp);

        return del;
    }
}

void printStack(){
    if(top == nullptr){
        cout<<"Empty string";
    }
    node* temp=top;
    while(temp!=nullptr){
        cout<<temp->data << " ";
        temp=temp->next;
    }
    cout<< endl;
}


int main(){
    int arr[] = {10,20,30,40,50,60,70,55,8,2,9};
    int len = sizeof(arr)/sizeof(arr[0]) ;

    for(int i=0; i< len ; i++){
        push(arr[i]);

    }


    printStack();

    for(int i=0 ; i<len ; i++){
         arr[i]  = pop();    //store as reverse array //
    }

    cout<< "reversed array : ";

    for(int i=0; i< len ; i++){
         cout << arr[i] << " ";

    }


    return 0;


}
