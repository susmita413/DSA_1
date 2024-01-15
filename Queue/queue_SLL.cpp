// Queue using single linked list
// 

# include <iostream>
using namespace std ;

class SinglyLL_Queue{
     class node {
        public:
        int data ;
        node* next ;
        node(int data){
            this->data = data;
            this->next = NULL ;
        }
    };
    node* front; //top
    node* rear;
    public:
    SinglyLL_Queue(){
        this->front= NULL ;
        this->rear = NULL;
    }

    bool isEmpty(){
         return front== NULL ;
    }

    void enqueue(int data){    //insert 
        node* newNode = new node(data);
        if(isEmpty()){
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = rear->next;
    }
    
    void dequeue(){    // delete 
        if(isEmpty()){
          cout<< " empty Queue list." ;
          return; 
        }
        node* del = front ;
        front= front->next ;
        delete(del);
    }

    void peek(){
       if(isEmpty()){
          cout << " empty Queue list." ;
       }
       else{
          cout << "Top most data: " << front->data << endl;
       }
    }
    void display_queue(){
         if(isEmpty()){
            cout << " empty Queue list." ;
         }
         node* cur = front ;
         while(cur != NULL ){
            cout << cur->data << endl ;
            cur = cur->next ;
         }
        cout << endl << endl ;
    }
};


int main (){

    SinglyLL_Queue data;

    data.enqueue(10);
    data.enqueue(20);
    data.enqueue(30);
    data.enqueue(40);
    data.display_queue();
    data.peek();

     if(data.isEmpty()){
        cout<< "showing empty Queue.\n" ;
     }
     else{
        cout<< " there is a queue list.\n"  ;
     }
     
    data.dequeue();
    data.dequeue();
    data.peek();
    data.dequeue();
    data.dequeue();
    data.display_queue();

    
     
    
}

/* 
    data.enqueue(50);
    //data.enqueue(60);
    data.peek();
    data.display_queue();
*/
