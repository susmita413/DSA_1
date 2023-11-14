// doubly linked List // edited 
// susmita paul //

#include <iostream>
using namespace std;

class doublyLinkedLinst{
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

    node* head;
    node* tail ;
    public :
    doublyLinkedLinst(){
        this->head = NULL ;
        this->tail = NULL ;
    }



    void addToTail(int data){

        node* newNode = new node(data);
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
            return ;
        }

        node* cur = head ;
        while( cur->next != NULL){
            cur = cur->next ;
        }
        
        cur->next = newNode ;
        newNode->prev = cur ;
        tail = newNode ;
    }

    void addToHead(int data){
        
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
            return ;
        }

        head->prev= newNode ;
        newNode->next = head ;
        head = newNode ;

    }

    void valueInsertAfter(int data, int num){
        
        node* newNode = new node(data);
        if(head == NULL){
           cout << "empty List" << endl ;
           return ;
        }
        
        node* cur = head;
        while(cur != nullptr && cur->data != num){
            cur = cur->next;
        }
        if(cur == NULL){
             cout<<"Invalid postion"<<endl;
            return;
        }

        node* temp ;
        temp= cur->next ;
        cur->next = newNode;
        newNode->next = temp;

    }

    void valueInsertBefore(int data , int num){
        node* newNode = new node (data) ;

        if(head == NULL){
            head = newNode;
            tail = newNode ;
            head->prev = newNode;
            head->next = newNode;
            return ;
        }
        
        node* cur = head ;
        while(cur->next != head && cur->next->data != num ){
            cur = cur->next ;
        }

        if(cur->next->data!= num){
            cout << "invalid input " << endl ;
            return ;
        }

        node* temp;
        temp = cur->next ;
        cur->next = newNode; 

        newNode->prev = cur ;
        newNode->next = temp;
        temp->prev = newNode ;


    }
    
    void printrevers(){
        if(tail== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=tail;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if (currentNode->prev != nullptr) {
                cout<<"->";
            }
            currentNode=currentNode->prev;
        }
    }


    void printList(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=head;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }

        cout<< endl ;
    }

 void deletion(int num ){
        if(head == NULL){
            cout<< "list is empty. " ;
            return ;
        }

        if(head->data == num ){
            node* temp= head->next ;
            temp->prev = head->prev ;
            node* del = head ;
            head = head->next ;
            delete del ;
            return ;
        }

        node* cur = head ;
        while(cur->next != head && cur->next->data != num){
            cur= cur->next ;
        }
        
        if(cur->next->data != num ){
            cout << "Invalid Number " << endl ;
        }

        node* temp1= cur;
        node* temp2 = cur->next->next ;
        node* del= cur->next ;

        temp1->next = temp2;
        temp2->prev = temp1 ;
        delete del ;

    }

};

int main(){

    doublyLinkedLinst data ;
    data.addToTail(10);
    data.addToTail(20);
    data.addToTail(30);
    data.addToTail(40);
    data.addToTail(50);
    data.addToTail(60);

 //   data.addToHead("00");
//    data.addToHead("01");
 //   data.addToHead("02");
//    data.addToHead("03");
    data.printList();

    //data.printrevers();
  //  data.valueInsertAfter("150","60");
    data.printList();

    return 0 ;
}