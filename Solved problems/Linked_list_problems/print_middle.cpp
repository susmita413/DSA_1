// Find the middle of a given linked list
// Created by User on 11/21/2023.
//

# include <iostream>
using namespace std ;

class SinglyLinkedList{
    class node {
    public:
        int data ;
        node* next ;
        node(int data){
            this->data = data;
            this->next = NULL ;
        }
    };
    node* head;
    public:
    SinglyLinkedList(){
        this->head = NULL ;
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

    void findMiddle(){
        node* cur= head;
        int count=0;
        while(cur != nullptr){
            cur = cur->next;
            count++;
        }
        cout << "length: " << count <<endl ;
        int mid = count/2 ;

        int i=0;
        cur =head;
        while(i<mid){
            cur = cur->next;
            i++ ;
        }
        cout << "Mid element : " << cur->data <<endl ;
    }


    void display_LL(){
        if(head == NULL){
            cout << " empty Linked list." ;
        }
        node* cur = head;
        while(cur != NULL ){
            cout << cur->data ;
            if(cur->next != nullptr ){
                cout << " -> " ;
            }
            cur = cur->next ;
        }
        cout << endl << endl ;
    }
};


int main (){

    SinglyLinkedList data;


    data.AddLast(10);
    data.AddLast(20);
    data.AddLast(30);
    data.AddLast(40);
    //data.AddLast(50);
    //data.AddLast(50);
    //data.AddLast(60);

    data.display_LL();
    data.findMiddle();

}


/*
 * 2nd way, find middle--
     void printMid(){
         Node* cur= head;
         int count =0, mid ;
         while(cur != nullptr){
             cur =cur->next;
             count++ ;
         }
         if(count%2 ==0){
              mid= count/2 ;
         }
         else{
              mid = (count/2) +1 ;
         }
         cur =head;
         for(int i=1; i<=mid ; i++){
             if(i== mid){
                 cout<< "Mid Value: " << cur->data << endl ;
                 break;
             }
             cur= cur->next;
         }

     }
*/



