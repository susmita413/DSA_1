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
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        node* cur = head ;
        while( cur->next != NULL ){
            cur =  cur->next ;

        }
        cur->next = newNode  ;
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

    void display_LL(){
         if(head == NULL){
            cout << " empty Linked list." ;
         }
         node* cur = head;
         while(cur != NULL ){
            cout << cur->data ;
            if(cur->next != nullptr ){
                 cout << " -> " ;
            }
            cur = cur->next ;
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
    data.AddLast(50);
    data.AddLast(60);
    
    data.addFirst(01);
    data.addFirst(02);
    data.addFirst(03);

    data.display_LL();

}





