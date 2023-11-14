# include <iostream>
using namespace std ;


class SinglyLinkedList{

    class node {

        public:

        string data ;
        node* next ;


        node(string data){
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
    void AddLast(string data){      

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


 /// --- if blank, 1st node create and if not blank, then create a node before 1st node. --- ///
    void addFirst(string data){      

          node*  newNode = new node(data) ;
          
          if(head == nullptr){

              head = newNode ;
              return ;
          }
          
          newNode->next = head ;
          head = newNode ;


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

    
    data.AddLast("10");
    data.AddLast("20");
    data.AddLast("30");
    data.AddLast("40");
    data.AddLast("50");
    data.AddLast("50");
    data.AddLast("60");
    
    data.addFirst("00");
    data.addFirst("01");
    data.addFirst("02");

    data.display_LL();

}





