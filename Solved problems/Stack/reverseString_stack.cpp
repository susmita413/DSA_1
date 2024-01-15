// reverse string // 

#include <iostream>
using namespace std;

struct list {
    char data;
    struct list* next;
};

typedef struct list node;
node* top = NULL;

void push(char x){
     node* temp = new node ;
     temp->data = x;
     temp->next = top;
     top = temp;
}

char pop(){
    if(top == nullptr){
        cout << " Empty stuck.\n" ;
        return 0;
    }
    else{
        char del = top->data ;
        node* temp = top;
        top = top->next;
        delete(temp) ;
        return del;
    }
}

int main(){

   string arr = "abcdefgh" ;
   
    for(int i=0; i<arr.length() ; i++){
        push(arr[i]);

    }

    for(int i=0 ; i<arr.length() ; i++){
        arr[i] = pop();     //store as reverse array //
    }

    cout<< "reversed string : ";

    for(int i=0; i<arr.length() ; i++){
         cout << arr[i] ;

    }


    return 0;


}