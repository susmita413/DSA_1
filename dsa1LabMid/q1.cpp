
#include <iostream>
using namespace std;

class doublyLinkedLinst{
    public:
    class node{
        public:
        node* prev ;
        int data;
        node* next ;
        node(int data){
            this->prev = nullptr ;
            this->data = data;
            this->next = nullptr ;
        }
    };
    node* head;
    node* tail ;
    public :
    doublyLinkedLinst(){
        this->head = NULL ;
        this->tail = NULL ;
    }



    void addToTail(int data){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
            return ;
        }
        node* cur = head ;
        while( cur->next != NULL){
            cur = cur->next ;
        }
        cur->next = newNode ;
        newNode->prev = cur ;
        tail = newNode ;
    }
    
    void ascend_sort(){
        node* cur;
        node* index;
        int temp ;
        if(head == nullptr){
            cout<< "empty list\n " ;
            return ;
        }
        else{
            for(cur = head; cur->next != nullptr ; cur= cur->next){
                for(index = cur->next ; index != nullptr ; index = index->next){
                    if(cur->data > index->data){
                           temp = cur->data ;
                           cur->data = index->data ;
                           index->data = temp ;
                    }
                }
            }
        }
        
    }

    
    void display_DLL(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }
        node* cur=head;
        while (cur!= nullptr){
            cout<<cur->data;
            if(cur->next!= nullptr){
                cout<< " <-> ";
            }
            cur = cur->next;
        }
        cout<< endl ;
    }

};

int main(){
    doublyLinkedLinst data ;
    data.addToTail(25);
    data.addToTail(20);
    data.addToTail(1);
    data.addToTail(5);

    data.display_DLL();
    data.ascend_sort();

    data.display_DLL();
    return 0 ;
}

