// Not complete
// Write a function to get the intersection point of two Linked Lists
// Created by User on 11/30/2023.
//
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

void display_LL(node* head){
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

int main(){
    node* head1 = new node;
    head1->data = 10;

    head1->next = new node;
    head1->next->data = 20;
    head1->next->next = new node;
    head1->next->next->data = 30;

    head1->next->next->next = new node;
    head1->next->next->next->data = 40;
    head1->next->next->next->next = new node;
    head1->next->next->next->next->data = 50;
    head1->next->next->next->next->next = nullptr ;

    node* head2 =new node;
    head2->data = 100;
    head2->next = head1->next->next ;
    display_LL(head1);
    display_LL(head2);
}