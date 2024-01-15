//
// 1st node’s new value is equal to the last node’s value minus first node’s current value,
//  likewise for first half nodes
// Created by User on 12/1/2023.
//


#include <iostream>
using namespace std;
class doublyLinkedList{
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
    doublyLinkedList(){
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

    void modify(){
        int count =1, mid ;
        node* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
            count++ ;
        }
        if(count == 1){
            cout<< "no need to modify\n" ;
            return;
        }
        mid = (count/2) +1 ;
        cur = head;
        node* cur2 = tail ;
        for(int i=1; i<mid ; i++){
            cur->data = (cur->data) - (cur2->data);
            cur = cur->next;
            cur2 = cur2->prev ;
        }
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
                cout<<" -> ";
            }
            cur = cur->next;
        }
        cout<< endl ;
    }

};

int main(){
    doublyLinkedList data ;
    data.addToTail(10);
    data.addToTail(20);
    data.addToTail(30);
    data.addToTail(4);
    data.addToTail(5);


    data.display_DLL();

    data.modify();

    data.display_DLL();
    return 0 ;
}
