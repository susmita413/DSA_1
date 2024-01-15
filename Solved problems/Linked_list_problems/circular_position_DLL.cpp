//
// Created by User on 12/1/2023.
// Circular linked list print from a given position

#include <iostream>
using namespace std;
class doublyLinkedList {
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
    doublyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
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
            cout << cur->data ;
            cur = cur->next ;
            if(cur != head){
                cout << "->" ;
            }
        }while (cur != head) ;
        cout<< endl ;
    }

    void print(node* start){
        node* temp = start;
        do{
            cout<< temp->data;
            temp = temp->next;
            if(temp != start) {
                cout << "->";
            }
        }while(temp!= start);
    }

    void circular_print(int pos){
        if(pos == 1){
            printLL(); return ;
        }
        node* cur = head;
        for(int i=1; i<pos; i++){
            cur = cur->next;
        }
        print(cur);
        cout << endl ;
    }

};


int main(){
    doublyLinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.printLL();
    list.circular_print(2);
}