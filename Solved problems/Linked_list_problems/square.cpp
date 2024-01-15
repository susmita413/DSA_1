// Insert the square of the first element into the end of the linked list.
// Created by User on 11/22/2023.
//
# include <iostream>
using namespace std ;

class SinglyLinkedList{
    class node {
    public:
        int data ;
        node* next ;
        node(int data){
            this->data = data;
            this->next = NULL ;
        }
    };
    node* head;
public:
    SinglyLinkedList(){
        this->head = NULL ;
    }


    void AddLast(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        node* cur = head ;
        while( cur->next != NULL ){
            cur =  cur->next ;
        }
        cur->next = newNode  ;
    }



    void display_LL(){
        if(head == NULL){
            cout << " empty Linked list." ;
        }
        node* cur = head;
        while(cur != NULL ){
            cout << cur->data ;
            if(cur->next != nullptr ){
                cout << " -> " ;
            }
            cur = cur->next ;
        }
        cout << endl << endl ;
    }

    void square(){
        int sq = (head->data) * (head->data);
      //  AddLast(sq);
        node* newNode = new node(sq);
        if(head == NULL){
            head = newNode;
            return;
        }
        node* cur = head ;
        while( cur->next != NULL ){
            cur =  cur->next ;
        }
        cur->next = newNode  ;
        cout << "after Insert the square of the first element into the end of the linked list.\n" ;
        display_LL();
    }
};


int main (){

    SinglyLinkedList data;


    data.AddLast(2);
    data.AddLast(5);
    data.AddLast(10);
    data.AddLast(8);
    data.AddLast(0);
    //data.AddLast(85);


    data.display_LL();

    data.square();

    data.display_LL();
}

