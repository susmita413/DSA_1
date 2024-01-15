// node create  using  loop//

# include <stdio.h>
# include <stdlib.h>

struct node{

   int data ;
   struct node *next ;
};

int main (){

    int choice=1 ;
    struct node *head, *newNode , *temp ;
              // temp work  as current Node //

    head= NULL ;

    while( choice == 1 ){
        newNode = (struct node *)malloc (sizeof(struct node)) ;

        printf(" enter data : ");
        scanf("%d", &newNode->data) ;

        newNode->next = NULL ;

        if(head == NULL){
            head = temp = newNode ;
        }

        else{
            temp->next = newNode ;
            temp = newNode ;

        }
 
        printf(" enter 1 to CONTINUE and enter 0 to EXIT : ") ;
        scanf("%d", &choice) ;

    }
    
    printf("\n\n") ;

    temp = head ;
    while(temp != NULL){

        printf(" %d " ,temp->data);
        temp = temp->next ;

        if(temp->next != NULL ){
            printf(" -> ") ;
        }
    }


    return 0 ;
}
