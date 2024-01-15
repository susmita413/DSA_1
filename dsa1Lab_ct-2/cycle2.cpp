#include<iostream>
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


    void AddLast( int data){

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


   int DetectLoop(){
        if(head == nullptr){
            return 0;
        }

        node* point1 = head;
        node* point2 = head;
        while(point1!= nullptr && point1->next!=nullptr){
            point2 = point2->next;
            point1 = point1->next->next;
            if(point2==point1){
                return 1;
            }
        }
        return 0;
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


    data.AddLast(12);
    data.AddLast(4);
    data.AddLast(3);
    data.AddLast(2);
    data.AddLast(1);
    data.AddLast(4);
    data.AddLast(3);
    data.AddLast(2);
    data.AddLast(1);


    data.display_LL();
    int res = data.DetectLoop();

    if (res == 1) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }



}