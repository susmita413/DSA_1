//the element is always deleted from front position.
// Created by User on 11/30/2023.
//
#include <iostream>
using namespace std ;
class circularLL {
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
    circularLL() {
        this->head = NULL;
    }

    void Add(int data) {
        node *newNode = new node(data);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        node *cur = head;
        while (cur->next != head) {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->next = head;
    }

    void deleteFirst(){
        if(head== nullptr){
            cout<< "empty List\n";
            return;
        }
        if(head->next == head){
            head = nullptr; return;
        }
        node* cur = head;
        node* del = cur;
        while(cur->next != head){
            cur = cur->next;
        }
        cur->next = head->next;
        head = head->next ;
        delete del;
    }

    void printList() {
        if (head == nullptr) {
            cout << "Empty LinkedList";
            return;
        }
        node *cur = head;
        do {
            cout << cur->data;
            if (cur->next != head) {
                cout << "->";
            }
            cur = cur->next;
        } while (cur != head);
        cout << endl;
    }
};

int main(){
    circularLL list;
    list.Add(10);
    list.Add(20);
    list.Add(30);
    list.Add(40);
    list.Add(50);
    list.Add(60);

    list.deleteFirst();
    list.printList();
    list.deleteFirst();
    list.printList();

}