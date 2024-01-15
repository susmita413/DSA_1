// sort ascending order and find minimum.
// find minimum without sorting
// Created by User on 11/22/2023.
//
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

    void find_minimum(){
        //LLsort();
     //   cout<< "minimum value: " << head->data << endl ;

        node *cur = head;
        node* min= head;
        while(cur != nullptr){
            if((cur->data) < (min->data)){
                min = cur ;
            }
            cur = cur->next ;
        }
        cout << "minimum value: " << min->data << endl ;
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

    data.AddLast(25);
    data.AddLast(100);
    data.AddLast(40);
    data.AddLast(5);
    data.AddLast(-5);
    data.AddLast(25);


    data.display_LL();

    data.find_minimum();

    data.display_LL();
}

