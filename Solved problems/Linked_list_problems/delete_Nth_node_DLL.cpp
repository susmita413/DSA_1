//
// delete given position node.
// Created by User on 11/30/2023.
//
#include <iostream>
using namespace std;

class doublyLinkedLinst {
public:
    class node {
    public:
        node *prev;
        int data;
        node *next;

        node(int data) {
            this->prev = nullptr;
            this->data = data;
            this->next = nullptr;
        }
    };

    node *head;
    node *tail;
public :
    doublyLinkedLinst() {
        this->head = NULL;
        this->tail = NULL;
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

    void delete_N(int pos){
        node* cur = head;
        if(pos==1){
            node* del = head;
            head= head->next ;
            head->prev = nullptr ;
            return ;
        }
        int i=1;
        while(cur->next != nullptr && i<pos){
            cur = cur->next ;
            i++ ;
        }
        if(cur->next == nullptr){
            node* del = cur;
            cur->prev->next = nullptr ;
            delete del;
            return ;
        }
        if(cur == nullptr){            //don't work //
            cout<< "wrong position\n" ;
            return;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev ;
        node* del = cur;
        delete del;
    }


    void display_DLL(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        node* cur=head;
        while (cur!= nullptr){
            cout<<cur->data;
            if(cur->next!= nullptr){
                cout<<"->";
            }
            cur = cur->next;
        }
        cout<< endl ;
    }
};


int main(){

    doublyLinkedLinst list;
    list.addToTail(10);
    list.addToTail(20);
    list.addToTail(30);
    list.addToTail(40);
    list.display_DLL();
    list.delete_N(1);
    list.display_DLL();
}
