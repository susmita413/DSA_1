// single linked list // susmita paul
/* Function = AddLast, AddLast, InsertAfetr, InsertBefore,
              reverse , reverse and print (List puro reverse hoyna)
              delete, display
*/


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

    void Insertafter(string data, string num){

        if(head == NULL){
            cout << "List is empty." << endl ;
            return ;
        }

        node* newNode = new node(data);
        node* cur = head ;
        while(cur != NULL && cur->data != num){
                cur = cur->next ;
         }

        if(cur == NULL){         // here why condition is not " cur->data != num " ???
                cout << "Invalid input number." << endl ;
                return;
        }
        newNode->next = cur->next ;
        cur->next = newNode ;

    }

    void InsertBefore(string data, string num){

        if(head == NULL){
            cout << "List is empty." << endl ;
            return ;
        }

        node* newNode = new node(data);
        if(head->data == num){
            newNode->next = head ;
            head = newNode ;
            return ;
        }

        node* cur = head ;
        while(cur->next != NULL && cur->next->data != num){
                cur = cur->next ;
         }

        if(cur == NULL){            /** here why condition is not " cur->data != num " ??? -- cur=NULL hole
                                     setar r next address /next->data kivabe thakbe //
                                     */
                cout << "Invalid input number." << endl ;
                return;
        }
        newNode->next = cur->next ;
        cur->next = newNode ;

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

    void deletion ( string value ){

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


int main (){

    SinglyLinkedList data;

    
    data.AddLast("10");
    data.AddLast("20");
    data.AddLast("30");
    data.AddLast("40");
    data.AddLast("50");
    data.AddLast("50");
    data.AddLast("60");

   // data.addFirst("00");
 //   data.addFirst("01");
 //   data.addFirst("02");

    data.display_LL();
     data.InsertBefore("320","10");
    //data.Insertafter("320","30");

   //   data.revresAndPrint() ;
 //   data.deletion("80");
  //  data.deletion("20");

    data.display_LL() ;

}

/**
 * data.AddLast("10");
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


    data.deletion("80");
*/