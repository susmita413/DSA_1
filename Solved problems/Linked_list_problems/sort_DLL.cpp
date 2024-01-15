
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

    void bubbleSort(int a[], int n){
        int temp ;
        for(int i=0; i<n-1 ; i++){
            int flag=0 ;
            for(int j=0; j<n-1-i; j++){
                if(a[j]> a[j+1]){
                    temp= a[j];
                    a[j] = a[j+1];
                    a[j+1]= temp;
                    flag=1;
                }
            }
            if(flag==0 ){
                break ;
            }
        }
    }

    void LLsort(){
        int a[100];
        node* cur = head;
        int i=0;
        while(cur != NULL){
            a[i] = cur->data;
            cur = cur->next;
            i++ ;
        }

        bubbleSort(a,i);

        i=0;
        node* cur2 = head;
        while( cur2 != NULL ){
            cur2->data = a[i];
            cur2 =  cur2->next ;
            i++ ;
        }
    }

    void printRevers(){     // reverse print, not change Linked list//
        if(tail== nullptr){
            cout<<"Empty List";
            return;
        }
        node* currentNode=tail;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if (currentNode->prev != nullptr) {
                cout<<"->";
            }
            currentNode=currentNode->prev;
        }
        cout<< endl ;
    }


    void display_DLL(){
        if(head== nullptr){
            cout<<"Empty List";
            return;
        }

        node* currentNode=head;
        while (currentNode!= nullptr){
            cout<<currentNode->data;
            if(currentNode->next!= nullptr){
                cout<<"->";
            }
            currentNode=currentNode->next;
        }

        cout<< endl ;
    }

};

int main(){

    doublyLinkedLinst data ;
    data.addToTail(80);
    data.addToTail(2);
    data.addToTail(30);
    data.addToTail(15);
    data.addToTail(100);
    data.addToTail(16);


    data.display_DLL();
    data.LLsort();
    data.display_DLL();
    data.printRevers();
    return 0 ;
}
