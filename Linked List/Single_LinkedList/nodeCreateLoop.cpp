// not complete // thikmoto kaj korena //


# include <iostream>
using namespace std ;

struct node{
    int data ;
    struct node* next;
};

 struct node* head = NULL ;



void addLast(int data){

    struct node* newNode ;

    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data ;
    newNode->next = NULL ;

    if(head == NULL){
        head = newNode ;
       return ;
    }

    struct node* currentNode = head ;
    while(currentNode->next != NULL){

        currentNode = currentNode->next ;
    }
    currentNode->next = newNode ;


}

void display(){

     if(head == NULL){

     cout << " empty Linked list." ;
     return ;
    }

    struct node* currentNode = head ;

    while(currentNode != NULL ){

        cout << currentNode->data ;
        if(currentNode->next != NULL ){
            cout << " -> " ;
        }

         currentNode = currentNode->next ;
    }

    cout << endl << endl ;
}


int main(){
   
    
   
   addLast(10);
    addLast(20);
    addLast(30);
    

    display();

    return 0 ;
}