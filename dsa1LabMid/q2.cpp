

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
  

    void delete_pos(int pos){
        node* cur = head;
        if(pos==1){
            node* del = head;
            head= head->next ;
            return ;
        }
        int i=1;
        while(cur->next != nullptr && (i+1)<pos ){
            cur = cur->next ;
            i++ ;
        }
        if(cur == nullptr){            
            cout<< "wrong position\n" ;
            return;
        }
        node* del = cur->next ;
        cur->next = cur->next->next ;
        delete del;
        return;
    }

    void delete_k(int pos){
        node* cur = head ;
        int count = 0 ;
        while(cur != NULL ){
            cur = cur->next ;
            count++ ;
        }
        int front_pos = (count - pos) +1 ;
         delete_pos(front_pos);
         cout<< " deleted\n " ;
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

    
    data.AddLast(3);
    data.AddLast(8);
    data.AddLast(2);
    data.AddLast(21);
    data.AddLast(9);
    data.AddLast(11);
  
    data.display_LL();
    data.delete_k(2);

   data.display_LL() ;

}



