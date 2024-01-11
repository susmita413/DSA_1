//selection sort ascending order

#include<iostream>
using namespace std;

void swap(int A[],int i,int min){
    int temp = A[i];
    A[i] = A[min];
    A[min] = temp ;
}

void selectionSort(int A[],int n){
    int min ;
    for(int i =0; i<n-1 ; i++){
        min = i;
        for(int j= i+1; j<n ; j++){
            if(A[min]>A[j])
                min = j ;
        }
        if(min != i){
            swap(A,i,min);
        }
    }
}

int main(){
    int arr[]= {9,3,5,13,18,43,2,5};
    int size = sizeof(arr)/sizeof(arr[0]) ;
    cout<< "before sorting: " ;
    for(int i =0; i<size ; i++){
        cout<< arr[i] << " " ;
    }

    selectionSort(arr,size);
    cout<<"\n After sorting: " ;
    for(int i =0; i<size ; i++){
        cout<< arr[i] << " " ;
    }
}
