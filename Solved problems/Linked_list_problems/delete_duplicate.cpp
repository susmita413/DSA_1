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


 //  / // 1st node create and node create one after another //
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


    void duplicateDelete(){

        node* cur = head ;

        while(cur != NULL ){
            
            node* cur2 = cur->next ;
            while( cur2 != NULL){

                if(cur->data == cur2->data){
                    deletion(cur->data);
                }

                cur2 = cur2->next ;
            }
            cur = cur->next ;

        }
    }


     void deletion ( int value ){

        if(head == NULL){
            cout << " empty List" ;
            return ;
        }

        if (head->data == value){
            node *toDelete = head;
            head = head->next ;
            delete toDelete ;
            return ;
        }

        node *currentNode = head ;

        while(currentNode->next != NULL && currentNode->next->data != value){
            currentNode = currentNode->next ;
        }

        if(currentNode->next == NULL){
            cout << "invalid input. " << endl ;
            return ;
        }

        node *toDelete = currentNode->next ;
        currentNode->next = currentNode->next->next ;

        delete toDelete ;

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
    
    SinglyLinkedList data ;

    data.AddLast(1);
    data.AddLast(2);
    data.AddLast(3);
    data.AddLast(4);
    data.AddLast(5);
    data.AddLast(3);
    data.AddLast(7);
    data.AddLast(8);
    data.AddLast(2);
    data.AddLast(10);

    data.display_LL();
    data.duplicateDelete();
    
    data.display_LL();
     return 0;

}