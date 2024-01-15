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


    void deleteN(node* temp){
        if(temp == tail){
            tail= tail->prev;
            tail->next = nullptr;
        }
        else{
            temp->prev->next = temp->next ;
            temp->next->prev = temp->prev ;
        }
        delete temp;
    }

    void removeDuplicate(){
        node* cur = head ;
        while(cur != nullptr){
            int check = cur->data;
            node* cur2 = cur->next ;
            while(cur2 != nullptr){
                if(check == cur2->data){
                    deleteN(cur2);
                }
                cur2 = cur2->next ;
            }
            cur = cur->next ;
        }
    }

    void printRevers(){     // reverse print, not change Linked list//
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
        cout<< endl ;
    }


    void display_DLL(){
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

};

int main(){

    doublyLinkedLinst data ;
    data.addToTail(8);
    data.addToTail(4);
    data.addToTail(4);
    data.addToTail(6);
    data.addToTail(4);
    data.addToTail(8);
    data.addToTail(4);
    data.addToTail(10);
    data.addToTail(12);
    data.addToTail(12);

    data.display_DLL();
    data.removeDuplicate();
    data.display_DLL();
    data.printRevers();
    return 0 ;
}

