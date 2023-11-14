// single linked list // susmita paul   //copied all from "SingleLL_BasicFunction.cpp"
/* Function = AddLast, AddLast, InsertAfetr, InsertBefore,
              reverse , reverse and print (List puro reverse hoyna)
              delete, display
    New add = searchByNumber  (can't handle duplicate number's all position search, 
                                here only 1st position can find)  
              searchMiddleElement      
*/


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


 /// --- if blank, 1st node create and if not blank, then create a node before 1st node. --- ///
    void addFirst(int data){      

          node*  newNode = new node(data) ;
          if(head == nullptr){
              head = newNode ;
              return ;
          }  
          newNode->next = head ;
          head = newNode ;
    }

    void Insertafter(int data, int num){

        if(head == NULL){
            cout << "List is empty." << endl ;
            return ;
        }
        
        node* newNode = new node(data);
        node* cur = head ;
        while(cur != NULL && cur->data != num){
                cur = cur->next ;
        }
        if(cur == NULL){       
                cout << "Invalid input number." << endl ;
                return;
        }
        newNode->next = cur->next ;
        cur->next = newNode ;

    }

    void InsertBefore(int data, int num){

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

    
    void searchByNum(int num) {
        node* cur = head ;
        int count = 0 ;
        while(cur != NULL && cur->data != num){
            cur = cur->next ;
            count++ ;
        }
        if(cur == NULL){
           cout << num << "  does not exist." << endl ;
           return;
        }
        cout << num << " is in position : " << count+1 << endl ;
        
    }

    
    int length(){
        node* cur = head ;
        int count = 0 ;
        while(cur != NULL ){
            cur = cur->next ;
            count++ ;
        }
        cout << " size is " << count << endl ;
        return count ;

    }

    void searchMid(){
        int size = length() ;
        int mid;
        if (size%2 == 0 ){
            mid = size/2 ;
        }
        else {
            mid = (size/2) + 1 ;
        }

        node* cur = head ;
        int count = 1 ;
        while(cur != NULL && count != mid ){
            cur = cur->next ;
            count++ ;
        }
        if (count == mid ){
            cout << "Mid data is : " << cur->data ;
        }

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


int main (){

    SinglyLinkedList data;

    
    data.AddLast(10);
    data.AddLast(20);
    data.AddLast(30);
    data.AddLast(40);
    data.AddLast(50);
   // data.AddLast(50);
    data.AddLast(60);
    
   // data.addFirst(1);
 //   data.addFirst(2);
 //   data.addFirst(3);

    data.display_LL();
  //   data.InsertBefore(320,10);
  //  data.Insertafter(320,30);

    //  data.searchByNum(40);
      data.searchMid();
    
   //  data.revresAndPrint() ;
 //  data.deletion(80);
  // data.deletion(20);

  //  data.display_LL() ;

}

/** 
 * data.AddLast(10);
    data.AddLast(20);
    data.AddLast(30);
    data.AddLast(40);
    data.AddLast(50);
    
    
    data.addFirst("00");
    data.addFirst("01");
    data.addFirst("02");

    data.display_LL();

    
    data.deletion("80");
*/