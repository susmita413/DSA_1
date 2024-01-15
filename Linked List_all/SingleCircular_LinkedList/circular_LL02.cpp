// single circular linked list //edited // susmita paul //
//

#include <iostream>
using namespace std ;

class circularLL{
     class node{
     public:
          string data;
          node* next ;

          node(string data){
            this->data = data ;
            this->next = NULL ;
          }
     };

     node* head ;
public:
     circularLL(){
        this->head = NULL ;
     }



     void Add(string data){
        node* newNode = new node(data) ;
        if(head == NULL){
          head = newNode ;
          newNode->next = head ;
          return ;
        }
        node* currentNode = head ;
        while(currentNode->next != head){

              currentNode= currentNode->next ;
        }
        currentNode->next =newNode ;
        newNode->next =head ;
     }

  //---- Data insert after "Given Number" --------------------//
     void ValueInsertAfter(string data, string num){
          
          if(head ==NULL ){
              cout << " list is empty " << endl ;
              return ;
          }

          node* cur = head;
          while( cur->next != head && cur->data != num){
               cur = cur->next  ;
          }

          if (cur->data != num ){
               cout << "Invalid number" << endl;
               return ;
          }

          node* newNode = new node(data);
          node* temp ;

          temp = cur->next ;
          cur->next = newNode ;
          newNode->next = temp ;

     }

  //------ Data insert Before "Given Number" --------------------//
     void ValueInsertBefore(string data, string num){

           if(head == NULL){
               cout << "list is empty " << endl ;
               return ;
           }

           node* cur = head ;
           while(cur->next != head && cur->next->data != num){
               cur= cur->next ;
           }

           if(cur->next->data != num ){
               cout << "Invalid number. " << endl ;
               return ;
           }

           node* newNode = new node (data) ;
           node* temp ;
           temp = cur->next ;
           cur->next = newNode ;
           newNode->next =  temp ;

     }

 //------------- delete "Given Number" -----------------------///
     void deletion(string value){
          if(head == NULL){
               cout << " List is empty. " << endl ;
               return ;
          }
           if(head->data == value){
               node* del = head ;
               head = head->next ;
               delete del ;
               return ;
           }
         

          node* cur = head ;
          while (cur->next != head && cur->next->data != value){
               cur = cur->next ;
          }
          
          if(cur->next->data != value){        // number ta list e nai //
               cout <<  "invalid value " << endl ;
          }
          node* del = cur->next ;
          cur->next = cur->next->next ;
          delete del ;


     }

     void printList(){
          if(head==nullptr){
            cout<<"Empty LinkedList";
            return;
          }
          node* currentNode =head;
          do{
               cout<<currentNode->data;
               if(currentNode->next!= head){
                        cout<<"->";
                }
               currentNode=currentNode->next;

          } while(currentNode != head) ;
        cout<<endl;
    }
};

int main(){

     circularLL data ;

     data.Add ("4");
     data.Add("8");
     data.Add("12");
     data.Add("16");
     data.Add("20");
     data.Add("24");
     data.Add("28");
     data.printList();

    // data.ValueInsertAfter("90","4");
   // data.ValueInsertBefore("100","4");

   data.deletion("100");
     data.printList();

     return 0 ;
}



/*
 if(head->data == value){
               node* del = head ;
               head = head->next ;
               delete del ;
               return ;
          }

*/