// reverse function //not change data, change pointer//
//size or list length function//

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
    
    int size(){
        int count=1;
        node* cur = head;
        while(cur->next != nullptr){
            cur = cur->next;
            count++ ;
        }
        return count;
    }
    

    void reverse(){
        node* prev = nullptr;
        node* cur = head;
        node* nextN = nullptr;
        while(cur->next != nullptr){
            nextN = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextN;
        }
        if(cur->next == nullptr){
              cur->next = prev;
              head = cur;  
        }  
    }
    
};


int main(){

    SinglyLinkedList data;
    data.AddLast(10);
    data.AddLast(20);
    data.AddLast(30);
    data.AddLast(40);
    data.AddLast(50);
    data.AddLast(60);
    data.display_LL();
    
    int si= data.size();
    cout<< "size: " << si <<endl ;
    data.reverse();
    data.display_LL();
}

/*
    chatgpt - decrease code's line

    void reverse() {
        node* prev = nullptr;
        node* cur = head;
        node* nextN = nullptr;

        while (cur != nullptr) {
            nextN = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextN;
        }
         head = prev; // Update the head to point to the new first node (which was the last node before reversal)
    }

*/