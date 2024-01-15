#include <iostream>
using namespace std;

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


    void AddLast(int  data){

        node* NewNodeObj = new node(data);

        if(head == NULL){
            head = NewNodeObj;
            return;
        }

        node* currentNode = head ;

        while( currentNode->next != NULL ){
            currentNode =  currentNode->next ;

        }

        currentNode->next = NewNodeObj  ;

    }

    void reverse(node* head) {
        if(head!= nullptr) {
            reverse(head->next);
            if (head->next != nullptr) {
                cout << "->";
            }
            cout << head->data;
        }

    }


    void revresAndPrint(){
        if(head==nullptr){
            cout<<"Empty List";
            return;
        }
        reverse(head);
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

int main (){

    SinglyLinkedList data;
    int exit= 1 ;
    while(exit != 0){

        int x;
        cin >> x;
        data.AddLast(x);
        cout << endl <<  " enter 0 or 1" << endl ;
        cin >> exit ;
    }

    data.display_LL();
    cout << " " << endl ;
    data.revresAndPrint();



}
