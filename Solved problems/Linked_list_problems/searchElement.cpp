//Search an element in a Linked List // single linked list//

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

    void Search(int x){
        int count=1;
        node*cur = head;
        while(cur->next != nullptr && cur->data != x){
            cur= cur->next ;
            count++ ;
        }
        if(cur->data != x){
            cout << x <<" is not in the List.\n ";
        }
        else{
            cout<< x <<" is in " << count <<"th node. \n";  
        }
      
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

int main(){

    SinglyLinkedList data;
    data.AddLast(10);
    data.AddLast(20);
    data.AddLast(30);
    data.AddLast(40);
    data.AddLast(50);
    data.AddLast(60);
    
    data.Search(60);
    data.display_LL();
}
