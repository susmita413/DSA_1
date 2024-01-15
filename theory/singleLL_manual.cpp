#include<iostream>
#include <stdlib.h>

using namespace std;

struct list{
    int data;
    struct list* next;
};

typedef struct list node;

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
}

int main(){

    node* head = (node*)malloc(sizeof(node)); //1st node create//
    head->data = 10;

    head->next = (node*)malloc(sizeof(node)); //2nd node create//
    head->next->data = 20;

    head->next->next = (node*)malloc(sizeof(node)); //3rd node create//
    head->next->next->data = 30;

    head->next->next->next = (node*)malloc(sizeof(node)); //4th node create//
    head->next->next->next->data = 40;

    head->next->next->next->next = nullptr; 

    printList(head);
    return 0;
}

/*  OR,
    node* head = (node*)malloc(sizeof(node)); //1st node create//
    head->data = 10;

    node* temp1 = (node*)malloc(sizeof(node)); //2nd node create//
    temp1->data = 20;

    node* temp2 = (node*)malloc(sizeof(node)); //3rd node create//
    temp2->data = 30;
   
    node* temp3 = (node*)malloc(sizeof(node)); //4th node create//
    temp3->data = 40;

    head->next = temp1 ;  
    head->next->next = temp2 ;
    head->next->next->next = temp3 ;
    head->next->next->next->next = nullptr; 

*/