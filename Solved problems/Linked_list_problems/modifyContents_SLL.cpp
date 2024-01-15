//
// 1st node’s new value is equal to the last node’s value minus first node’s current value,
//  likewise for first half nodes  //not complete//
// Created by User on 12/1/2023.
//
# include <iostream>
using namespace std ;

class SinglyLinkedList {
    class node {
    public:
        int data;
        node *next;

        node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };

    node *head;
public:
    SinglyLinkedList() {
        this->head = NULL;
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
        node* currentNode = head;
        while(currentNode != NULL ){
            cout << currentNode->data ;
            if(currentNode->next != nullptr ){
                cout << " -> " ;
            }
            currentNode = currentNode->next ;
        }
        cout << endl << endl ;
    }
};

int main(){
    SinglyLinkedList list ;
    list.AddLast(10);
    list.AddLast(20);
    list.AddLast(30);
    list.AddLast(40);
    list.display_LL();

}