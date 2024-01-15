// reverse individual words// hello world --> olleh dlrow 
// stack using  linked list//

#include <iostream>
using namespace std;

struct list {
    char data;
    struct list* next;
};

typedef struct list node;
node* top = NULL;

void push(char x){
     node* temp = new node ;
     temp->data = x;
     temp->next = top;
     top = temp;
}

char pop(){
    if(top == nullptr){
        cout << " Empty stuck.\n" ;
        return 0;
    }
    else{
        char del = top->data ;
        node* temp = top;
        top = top->next;
        delete(temp) ;
        return del;
    }
}

void wordReverse(string word){

    for(int i=0; i<=word.length(); i++){

        if(word[i]== ' ' || i == word.length()){
            while(top != NULL){
               char w = pop();
               cout << w ;
            }

           if(i != word.length()){
               cout << ' ' ;
           }
        } 
        
        else{
            push(word[i]);
        }
        
    }
}



int main(){

    string word= "Hello world " ;
    cout << word.length() << endl ;
    wordReverse(word);   
    
}

/*
   int i=j ;
        while(word[i] != ' ' && word[i] != '\0'){
            push(word[i]);
            i++ ;
        }

        int k= j;
        while(word[k] != ' ' && word[k] != '\0'){
            word[k] = pop();
            k++ ;
        }
*/

/*
    string chr(1,word[i]);
        push(chr);

*/

/* 
    void wordReverse(string word){

    for(int i=0; i<=word.length(); i++){
       int st = i;

        if(word[i]== ' ' || i == word.length()){
            for(int j=i-1 ; j>=st ; j--){
               char w = pop();
               cout << w ;
           }
      } 

      else{
        push(word[i]);
      }
        
    }
}
*/