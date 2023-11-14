# include <stdio.h>
# include <stdlib.h>

struct node{
   
   char data1;
   int data2 ;
   struct node *next ;


};


int main (){

    struct node *head ;

    head = (struct node *)malloc(sizeof(struct node)) ;

    head->data1 = 'a' ;
    head->data2 = 10 ;
    head->next = NULL ;

    struct node *currentNode ;

    currentNode = (struct node *)malloc (sizeof(struct node)) ;
    currentNode-> data1 = 'b' ;
    currentNode-> data2 = 20 ;
    head-> next = currentNode ;

    
    struct node *currentNode2 ;

    currentNode2  = (struct node *)malloc (sizeof(struct node)) ;
    currentNode2-> data1 = 'c' ;
    currentNode2 -> data2 = 30 ;
    currentNode-> next = currentNode2 ;


    printf("\n %c. %d \n", head->data1, head->data2) ;
    printf(" %c. %d \n", currentNode->data1, currentNode->data2) ;
    printf(" %c. %d \n", currentNode2->data1, currentNode2->data2) ;

    return 0;

}