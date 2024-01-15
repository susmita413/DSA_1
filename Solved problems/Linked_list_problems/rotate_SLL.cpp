//
// Created by User on 11/30/2023.
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

    void rotate(int pos){
        node* cur = head;
        node* th =head;
        for(int i=1; i<pos; i++){
            cur = cur->next ;
        }
        node* cur2 = cur;
        while(cur->next != nullptr){
            cur = cur->next ;
        }
        cur->next = th =head;
        head = cur2->next;
        cur2->next = nullptr;
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
    list.AddLast(50);
    list.AddLast(60);
    list.AddLast(70);
    list.display_LL();

    int pos;
    cout<< "enter rotate position: ";
    cin>> pos ;
    list.rotate(pos);
    list.display_LL();

}