//
// Created by User on 12/2/2023.
//

#include<iostream>
using namespace std;

class DoublyLinkedList{
    class node{
    public:
        node* prev;
        int data;
        node* next;
        node(int data){
            this->prev = nullptr;
            this->data = data;
            this->next= nullptr;
        }
    };
    node* head;
    node* tail;
public:
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail =nullptr;
    }

    void addTail(int value){
        node* newNode = new node(value);
        if(head == nullptr){
            head = newNode ;
            tail= newNode ;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        tail = newNode;
    }

    void reverse(){
        node* nextN;
        node* cur = head;
        tail = head;
        while(cur->next != nullptr){
            nextN = cur->next ;
            cur->next = cur->prev ;
            cur->prev= nextN;
            cur = nextN ;
        }
        if(cur->next == nullptr){
            cur->next = cur->prev ;
            cur->prev = nullptr;
            head = cur ;
        }
    }

    void reverse_K(int k){
        node* cur = head;
        int i=1;
        while(i<=k || cur->next != nullptr){

        }
    }

    void display_LL(){
        if(head == nullptr){
            cout<< "empty List\n" ;
            return;
        }
        node* cur =head;
        while(cur != nullptr){
            cout<< cur->data ;
            cur = cur->next ;
            if(cur != nullptr){
                cout << "->" ;
            }
        }
        cout<< endl ;
    }
};

int main(){
    DoublyLinkedList list ;
    list.addTail(10);
    list.addTail(20);
    list.addTail(30);
    list.addTail(40);
    list.addTail(50);
    list.addTail(60);
    list.addTail(70);

    list.display_LL();

    list.reverse();
    list.display_LL();
}