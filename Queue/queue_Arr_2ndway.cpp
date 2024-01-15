// circular queue //

#include <iostream>
using namespace std;

#define Qsize 3
int queue[Qsize];
int front =-1;
int rear= -1 ;

void enqueue(int data){
     if(front == -1 && rear ==-1){ // Queue empty //
          front = rear = 0;
          queue[rear] = data ;
     }
     else if(front == (rear+1)% Qsize){ // queue is full //
          cout<< "queue is OVERFLOW \n" ;
     }

     else{
          rear = (rear+1) % Qsize ;
          queue[rear] = data ;
     }
}

void dequeue(){
     int del ;
     if(front == -1 && rear == -1){    // Queue empty//
          cout<< "queue underflow\n" ;
     }
     else if(front == rear){  // queue has 1 data //
          del = queue[front];
          front = -1;
          rear = -1 ;
          cout<< "deleted data : " << del << endl ;
     }

     else{
          del = queue[front];
          queue[front] = 0 ;
          front = (front+1) % Qsize ;
          cout<< "deleted data : " << del << endl ;
     }
}
void peek(){
    if(front == -1 && rear ==-1){
       cout<< "\n Queue is empty.\n" ;
    }
    else{
       cout << "topmost number: " << queue[front] << endl; 
    }
    
}

void display(){
    if(front == -1 && rear ==-1){
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
    display() ;

    dequeue();
    display();
    peek();

    dequeue();
    display();
    dequeue();
    display();
    
     dequeue();
    display();

    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    display() ;

}