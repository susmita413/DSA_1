// work in main function --
/*  1. node create -- 10,20,30,40
    2. (insertinMid) insert 35, after 30 -- 10,20,30,35,40 
    3. (delete from mid) delete 30 -- 10,20,35,40
    4. singleLinked List to Circular LinkedList
    5. print single Linked List
    6. print circular Linked List
*/

#include<iostream>
#include <stdlib.h>

using namespace std;

struct list{
    int data;
    struct list* next;
};

typedef struct list node ;

void printCircularLL(node* first){
    if(first == NULL){
        cout<< "List is empty.\n" ;
    }

    node* temp = first ;
    do{
        cout<< temp->data ;
        if(temp->next != first){
            cout << " -> " ;
        }
        temp= temp->next ;
    }
    while(temp != first);
    cout<<endl ;

}

void printList(node* start){

    if(start == NULL){
        cout<< "List is empty.\n" ;
    }

    node* temp = start ;
    while(temp!= nullptr){
        cout<< temp->data ;
        if(temp->next != nullptr){
            cout << " -> " ;
        }
        temp= temp->next ;
    }
    cout<<endl ;
}

int main(){
    node* head = new node; //1st node create//
    head->data = 10;

    node* temp1 = new node ; //2nd node create//
    temp1->data = 20;
    

    node* temp2 = new node ; //3rd node create//
    temp2->data = 30;
   
    node* temp3 = new node ; //4th node create//
    temp3->data = 40;

    head->next = temp1 ;  
    head->next->next = temp2 ;
    head->next->next->next = temp3 ;
    head->next->next->next->next = nullptr; 

    printList(head);

    node* newitem = (node*)malloc(sizeof(node));
    newitem->data = 35;
    newitem->next = head->next->next->next ;       //insert 35, after node data= 30 //
    head->next->next->next = newitem ;
    head->next->next->next->next->next = nullptr; 
    printList(head);

    node* del = head->next->next;                 // delete 30 //
    head->next->next = head->next->next->next ;
    delete del;
    printList(head);

    head->next->next->next->next= head;           // singular linked list to circular linked list //
    printCircularLL(head);


    return 0;


}

/*
    head = head->next ;
    printList(head);

*/