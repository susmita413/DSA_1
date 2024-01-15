// doubly circular linked List //
// susmita paul //
// function- add, valueInsertAfter, value Insert Before, deletion, printList

#include <iostream>
using namespace std;

class doublyLinkedLinst{
    public:
    class node{
        public:
        node* prev ;
        string data;
        node* next ;
        node(string data){
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


    void add(string data){

        node* newNode = new node (data) ;

        if(head == NULL){
            head = newNode;
            tail = newNode ;
            head->prev = newNode;
            head->next = newNode;
            

            return ;
        }

        node* cur = head ;
        while (cur->next != head){
            cur = cur->next ;
        }

        cur->next = newNode ;
        newNode->prev = cur  ;   
        newNode->next = head ;
        head->prev = newNode ;


    }

    void ValueInsertafter(string data, string num){
         node* newNode = new node (data) ;

        if(head == NULL){
            head = newNode;
            tail = newNode ;
            head->prev = newNode;
            head->next = newNode;
            return ;
        }
        
        node* cur = head ;
        while(cur->next != head && cur->data != num ){
            cur = cur->next ;
        }

        if(cur->data!= num){
            cout << "invalid input " << endl ;
            return ;
        }

        node* temp ;
        temp= cur->next ;
        cur->next = newNode; 

        newNode->prev = cur ;
        newNode->next = temp;
        temp->prev = newNode ;

    }

    void valueInsertBefore(string data , string num){
        node* newNode = new node (data) ;

        if(head == NULL){
            head = newNode;
            tail = newNode ;
            head->prev = newNode;
            head->next = newNode;
            return ;
        }
        
        node* cur = head ;
        while(cur->next != head && cur->next->data != num ){
            cur = cur->next ;
        }

        if(cur->next->data!= num){
            cout << "invalid input " << endl ;
            return ;
        }

        node* temp;
        temp = cur->next ;
        cur->next = newNode; 

        newNode->prev = cur ;
        newNode->next = temp;
        temp->prev = newNode ;


    }

    void deletion(string num ){
        if(head == NULL){
            cout<< "list is empty. " ;
            return ;
        }

        if(head->data == num ){
            node* temp= head->next ;
            temp->prev = head->prev ;
            node* del = head ;
            head = head->next ;
            delete del ;
            return ;
        }

        node* cur = head ;
        while(cur->next != head && cur->next->data != num){
            cur= cur->next ;
        }
        
        if(cur->next->data != num ){
            cout << "Invalid Number " << endl ;
        }

        node* temp1= cur;
        node* temp2 = cur->next->next ;
        node* del= cur->next ;

        temp1->next = temp2;
        temp2->prev = temp1 ;
        delete del ;

    }

    void printLL(){

        if(head == NULL){
            cout << "List is empty ." << endl ;
            return ;
        }

        node* cur = head ;

        do{
            cout << cur->data << "  " ;
            cur = cur->next ;
        }while (cur != head) ;

        cout<< endl ;
    }


};


int main(){
    doublyLinkedLinst data ;
    data.add("10");
    data.add("20");
    data.add("30");
    data.add("40");
    data.printLL();

    data.ValueInsertafter("100","10");
    data.valueInsertBefore("100","40");
    data.deletion("30");
    data.printLL();
    return 0 ;
}

/*  
     void printList(){
            if(head== nullptr){
                cout<<"Empty List";
                return;
            }

            Node* currentNode=head;
            do{
                cout<<currentNode->data;
                if(currentNode->next!=head){
                      cout<<"->";
                }
                currentNode=currentNode->next;
            } while(currentNode!=head);
        }


*/

/*
    void Deletion(string value) {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node* currentNode = head;
        if (currentNode->data == value) {
            if (currentNode->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* lastNode = head->pre;
                head = head->next;

                lastNode->next = head;
                head->pre = lastNode;

                delete currentNode;
            }
            return;
        }

        currentNode = head;
        do {
            if (currentNode->data == value) {
                Node* toDelete = currentNode;
                Node* previousNode = currentNode->pre;
                Node* nextNode = currentNode->next;

                previousNode->next = nextNode;
                nextNode->pre = previousNode;

                delete toDelete;
                return;
            }
            currentNode = currentNode->next;
        } while (currentNode != head);
    }
*/

/*
    data.addToTail("10");
    data.addToTail("20");
    data.addToTail("30");
    data.addToTail("40");
*/

/*
     data.addToHead("1");
    data.addToHead("2");
    data.addToHead("3");
    data.addToHead("4");
*/