//
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

    void deleteMid(){      // works from: will give minimum 3 nodes//
        int count= 0, mid ;
        node* cur =head;
        while(cur != nullptr){
            count++ ;
            cur = cur->next ;
        }
        if(count%2 ==0)
            mid= count/2 ;
        else
            mid =(count/2) +1 ;

        cur = head;
        for(int i=1; i<mid ; i++){
            cur = cur->next;
        }
        node* del = cur ;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev ;
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


int main() {
    doublyLinkedLinst data;
    data.addToTail(10);
    data.addToTail(20);
    data.addToTail(30);
    //data.addToTail(40);

    data.display_DLL();
    data.deleteMid();
    data.display_DLL();

}