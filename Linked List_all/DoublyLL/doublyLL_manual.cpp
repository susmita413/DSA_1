//
// Created by User on 11/23/2023.
//

#include<iostream>
using namespace std;

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct  node *head;
struct node *tail;

void deleteLast(){
    node* del = tail;
    tail = tail->prev ;
    tail->next = nullptr ;
    delete del;
}

void insertAtMid(int value){
    node* cur = head;
    int count=0;
    while(cur!= nullptr){
        count++ ;
        cur = cur->next;
    }
    cout<< "length: " << count <<"\n after insert at mid:\n" ;
    int mid = count/2 ;
    node* newItem= new node;
    newItem->data = value ;
    int i=1;
    cur =head;
    while(i<mid){
        cur = cur->next;
        i++ ;             // atlast, i=mid and cur will point that mid node//
    }
    newItem->next = cur->next;
    newItem->prev = cur;
    cur->next->prev = newItem ;
    cur->next = newItem;
}


void printList(node* start){
    if(start== nullptr){
        cout<<"Empty List";
    }
    node* temp=start;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!= nullptr){
            cout<<"->";
        }
        temp=temp->next;
    }
    cout<< endl ;
}


void printList_Reverse(node* finish){
    if(finish == nullptr){
        cout<<"Empty List";
    }
    node* temp = finish ;
    while(temp != nullptr){
        cout<<temp->data;
        if(temp->prev != nullptr){
            cout<<"->";
        }
        temp=temp->prev ;
    }
    cout<< endl ;
}

int main(){

    head = new node ; //1st node create//
    head->data = 10;
    head->prev = nullptr ;

    head->next = new node ; //2nd node create//
    head->next->data = 20;
    head->next->prev = head;

    head->next->next = new node ; //3rd node create//
    head->next->next->data = 30;
    head->next->next->prev = head->next ;

   // head->next->next->next = new node ; //4th node create//
  //  head->next->next->next->data = 40;
   // head->next->next->next->prev = head->next->next ;

    head->next->next->next = nullptr;
    tail = head->next->next;

    printList(head);
   // printList_Reverse(tail);
   // deleteLast();
   // printList(head);
  //  printList_Reverse(tail);

    insertAtMid(300);
    printList(head);
    return 0;
}

