//
// Created by User on 12/1/2023.
//

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

    void rotate(int pos){
         if(pos<= 0){
             cout<<"invalid pos\n";  return ;
         }
         node* cur = head;
         for(int i =1; i<pos; i++){
             cur = cur->next ;
             if(cur == nullptr){
                 cout<< "invalid position\n" ;
                 return;
             }
         }
         tail->next = head;
         head->prev = tail;
         tail = cur;
         head = cur->next;
         cur->next->prev =nullptr;
         cur->next = nullptr ;
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
    doublyLinkedLinst data ;
    data.addToTail(10);
    data.addToTail(20);
    data.addToTail(30);
    data.addToTail(40);
    data.display_DLL();
    data.rotate(2);
    data.display_DLL();
    return 0 ;
}
