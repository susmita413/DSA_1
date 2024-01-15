// doubly linked List // edited 
/* susmita paul // function : addToTail(), addToHead(), valueInsertAfter(), //DONE
 *                         valueInsertBefore(),  display_DLL(), deletion(), //Done
 *                            printRevers(),   reverse()                    //DONE
*/

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

    void addToHead(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
            return ;
        }
        head->prev= newNode ;
        newNode->next = head ;
        head = newNode ;

    }

    void valueInsertAfter(int data, int num){
        node* newNode = new node(data);
        if(head == NULL){
           cout << "empty List" << endl ;
           return ;
        }
        node* cur = head;
        while(cur != nullptr && cur->data != num){
            cur = cur->next;
        }
        if(cur == NULL){
             cout<<"given number is not included in list. \n" ;
            return;
        }
        if(cur->next == NULL){    // insert after last number//
            cur->next = newNode;
            newNode->prev= cur;
            newNode->next = nullptr;
            tail= newNode;
            return;
        }
        node* temp ;
        temp= cur->next ;
        cur->next = newNode;
        temp->prev = newNode;
        newNode->next = temp;
        newNode->prev= cur;
    }


    void valueInsertBefore(int data , int num){
        node* newNode = new node (data) ;
        if(head == NULL){
           cout<< "empty list. \n" ;
        }
        node* cur = tail ;
        while(cur->prev != nullptr && cur->data != num ){
            cur = cur->prev ;
        }
        if(cur->prev == nullptr && cur->data != num){
            cout << "given number is not included in list. \n" ;
            return ;
        }

        if(cur->prev == nullptr && cur->data == num){   // insert before last value//
            cur->prev= newNode;
            newNode->next = cur;
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        newNode->prev =cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode ;
        cur->prev = newNode;


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

    void reverse(){     // reverse node address//
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        node* nextN;
        node* cur = head;
        tail = head;
        while(cur->next != nullptr){
            nextN = cur->next ;
            cur->next = cur->prev ;
            cur->prev= nextN;
            cur = nextN ;
        }
        if(cur->next == nullptr){
            cur->next = cur->prev ;
            cur->prev = nullptr;
            head = cur ;
        }
    }


    void deletion(int num ) {
        if (head == NULL) {
            cout << "list is empty. ";
            return;
        }
        if (head->data == num) {
            node *temp = head->next;
            temp->prev = head->prev;
            node *del = head;
            head = head->next;
            delete del;
            return;
        }
        node *cur = head;
        while (cur->next != nullptr && cur->next->data != num) {
            cur = cur->next;
        }
        if(cur->next == nullptr && cur->data != num){  // given number is not included in linked list//
            cout << "Invalid Number " << endl;
            return;
        }

        if(cur->next->next == nullptr && cur->next->data == num){ //last number delete //
            node *del1 = tail;
            tail = tail->prev;
            cur->next = nullptr;
            return;
        }
        node *del = cur->next;      // middle number delete//
        node *temp = cur->next->next;
        temp->prev = cur ;
        cur->next = temp ;
        delete del;

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

  //  data.addToHead(100);
  //  data.addToHead(200);
  //  data.addToHead(300);
  //  data.addToHead(400);

  //  data.valueInsertAfter(550,40);
   // data.valueInsertBefore(550,10);
    data.display_DLL();
  //  data.deletion(40);

    //data.printRevers();
      data.reverse();
    data.display_DLL();
    return 0 ;
}
