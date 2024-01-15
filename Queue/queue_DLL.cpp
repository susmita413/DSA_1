#include <iostream>
using namespace std;

class DLL{
    public:
    class node{
        public:
        node* prev ;
        int data;
        node* next ;
        node(int data){
            this->prev = nullptr ;
            this->data = data;
            this->next = nullptr ;
        }
    };

    node* front;
    node* rear ;
    public :
    DLL(){
        this->front = NULL ;
        this->rear = NULL ;
    }

    bool(isEmpty()){
        if(front == nullptr){
            return true ;
        }
        else{
           return false ; 
        }
    }

    void enqueue(int data){ //insert in rear
        
        node* newNode = new node(data);
        if(isEmpty()){
            front = newNode ;
            rear = newNode ;
            return ;
        }
       newNode->prev = rear ;
       rear->next = newNode ;
       rear = newNode ;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "queue empty.\n" ; return ;
        }
        node* del = front;
        front->next->prev = nullptr ;
        front = front->next ;
        delete del ;
    }

    void peek(){
        if(isEmpty()){
            cout << "queue empty.No front element\n" ; return ;
        }
        cout<< "topmost number: " << front->data << endl ;
    }


    void display_queueLL(){
        if(isEmpty()){
            cout << "queue empty.what should I do? \n" ; return ;
        }

        node* cur = front;
        while (cur != nullptr){
            cout<< cur->data << endl ;
            cur = cur->next;
        }
        cout<< endl ;
    }


};

int main(){

    DLL data ;
    data.display_queueLL();
    data.peek();
    data.enqueue(10);
    data.enqueue(20);
    data.enqueue(30);
    data.enqueue(40);
   // data.enqueue(50);
  //  data.enqueue(60);
    data.display_queueLL();
    data.peek();

    data.dequeue();
   
    return 0 ;
}