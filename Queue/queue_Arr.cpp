#include <iostream>
using namespace std;

#define size 3
int queue[size];
int front =-1;
int rear= -1 ;

bool is_Empty(){
    if(front>rear || front == -1  ){
        return true ;
    }
    else{
      return false;
    }
}

bool isFull(){
     if(rear== size-1){
       return true;
    }
    else{
       return false ;
    }
}

void enqueue(int data){
    if(isFull()){
       cout<< "\nQueue is Full\n" ;
       return;
    }
    if(front== -1){
        front++ ;
    }
    queue[++rear] = data;   
}

void dequeue(){
    if(is_Empty()){
        cout << "\nQueue is empty.\n" ;
        return ;
    }
    else{
      for(int i=front+1; i<=rear; i++){
         queue[i-1] = queue[i]; 
      }
      rear-- ;
    }
    if(rear== -1){
        front = -1;
    }
}

void peek(){
    if(is_Empty()){
       cout<< "\n Queue is empty.\n" ;
    }
    else{
       cout << "topmost number: " << queue[front] << endl; 
    }
    
}

void display(){
    if(is_Empty()){
        cout<<"\nEmpty list"<<endl;
    }
    else{
        for (int i = front; i <=rear  ; i++) {
            cout<< queue[i]<< endl ;
        }
        cout << endl;
    }
}


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    peek();

    dequeue();
    display();
    peek();

    dequeue();
    display();
    peek(); 
    
    dequeue();
    display();
    peek();

    enqueue(100);
    display();
    peek();

    return 0;
}

/*
     enqueue(510);
    enqueue(520);

    dequeue();
    dequeue();
    dequeue();
    display();
    peek();

    dequeue();
    display();
    peek();

*/