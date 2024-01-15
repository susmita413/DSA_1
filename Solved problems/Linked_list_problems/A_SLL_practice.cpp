#include<iostream>
using namespace std;

class SingularLinkedList{
     class node{
         public:
         int data;
         node* next;
         node(int data){
             this->data = data ;
             this->next = nullptr;
         }
     };
     node* head;
     public:
     SingularLinkedList( ){
          this->head =nullptr ;
     }
     
     void addList(int value){
          node* newNode = new node(value);
          if(head == nullptr){
               head = newNode ; 
               return ;
          }
          node* cur =head;
          while(cur->next != nullptr){
               cur = cur->next;
          }
          cur->next = newNode;
     }

     void printMid(){
         node* cur= head;
         int count =0, mid ;
         while(cur != nullptr){
             cur =cur->next;
             count++ ;
         }
         if(count%2 ==0){
              mid= count/2 ;
         }
         else{
              mid = (count/2) +1 ;
         }
         cur =head;
         for(int i=1; i<=mid ; i++){
             if(i== mid){
                 cout<< "Mid Value: " << cur->data << endl ;
                 break;
             }
             cur= cur->next;
         }

     }

     void reverse(){
         if(head== nullptr){
             cout<< "empty List\n" ;
         }
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
             head= cur;
         }
     }

     void reverseN_print(node* cur){  // 2nd way//
         if(cur->next != nullptr){
             reverseN_print(cur->next);
         }
         cout << cur->data << " " ;
     }

     void reverse_2(){              //2nd way//
         if(head== nullptr){
             cout<< "empty List\n" ;
         }
         reverseN_print(head);
         cout<< endl;
     }

     void display(){
         if(head== nullptr){
             cout<< "empty List\n" ;
         }
          node* cur = head;
          while(cur != NULL){
               cout<< cur->data;
               cur = cur->next;
               if(cur != nullptr){
                    cout << " -> ";
               }
          }
          cout << endl;
     }
};

int main(){
     SingularLinkedList list ;
     list.addList(10);
     list.addList(20);
     list.addList(30);
     list.addList(40);
     list.addList(50);
     list.addList(60);

     list.display();
     list.reverse_2();
    // list.printMid();
     list.display();
     return 0;
}
