// A program to take numbers from different machines and print them in sorted order 
// Sort numbers stored on different machines
/* Given N machines. Each machine contains some numbers in sorted form. 
But the amount of numbers, each machine has is not fixed. Output the numbers from all  
the machine in sorted non-decreasing form. 
*/

#include <iostream>
using namespace std;


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

    void bubbleSort(int a[], int n) {
        int temp;
        for (int i = 0; i < n - 1; i++) {
            int flag = 0;
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    flag = 1;
                }
            }
            if (flag == 0) {
                break;
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



int main()
{
    SinglyLinkedList data;
    int arr1[]= {1,-2,50};
    int len1= sizeof(arr1)/sizeof(arr1[0]);

    int arr2[]= {90,50};
    int len2= sizeof(arr2)/sizeof(arr2[0]);

    int arr3[]= {80,40,200,10,5};
    int len3= sizeof(arr3)/sizeof(arr3[0]);
    
    for(int i=0; i<len1; i++){
        data.AddLast(arr1[i]);
    }
    for(int i=0; i<len2; i++){
        data.AddLast(arr2[i]);
    }
    for(int i=0; i<len3; i++){
        data.AddLast(arr3[i]);
    }

    data.display_LL();
    cout<< " After sorting: \n" ;
    data.LLsort();
    data.display_LL();

    return 0;
}

