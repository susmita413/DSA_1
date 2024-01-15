// doubly linked list // 
// find pairs with given sum //

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


    void add(int data){

        node* newNode = new node (data) ;

        if(head == NULL){
            head = newNode;
            tail = newNode ;
            head->prev = newNode;
            head->next = newNode;
            return ;
        }

        node* cur = head ;
        while (cur->next != head){
            cur = cur->next ;
        }

        cur->next = newNode ;
        newNode->prev = cur  ;   
        newNode->next = head ;
        head->prev = newNode ;

    }

    void printLL(){

        if(head == NULL){
            cout << "List is empty ." << endl ;
            return ;
        }

        node* cur = head ;

        do{
            cout << cur->data << "  " ;
            cur = cur->next ;
        }while (cur != head) ;

        cout<< endl ;
    }

    void pair(int num){

        node* cur = head ;
        while(cur->next )
    }


};

int main(){
    
    doublyLinkedLinst data ;

    data.add(10);
    data.add(20);
    data.add(30);
    data.add(40);

    data.printLL();
    return 0 ;
}