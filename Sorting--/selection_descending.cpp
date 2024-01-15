//selection sort descending order
// Created by User on 1/11/2024.
//
#include<iostream>
using namespace std;

void swap(int A[],int i,int min){
    int temp = A[i];
    A[i] = A[min];
    A[min] = temp ;
}

void selectionSort_des(int A[],int n){
    int max ;
    for(int i =0; i<n-1 ; i++){
        max = i;
        for(int j= i+1; j<n ; j++){
            if(A[max]<A[j])           //changed condition//
                max = j ;
        }
        if(max != i){
            swap(A,i,max);
        }
    }
}

int main(){
    int arr[]= {9,-3,5,13,18,43,-2,5};
    int size = sizeof(arr)/sizeof(arr[0]) ;
    cout<< "before sorting: " ;
    for(int i =0; i<size ; i++){
        cout<< arr[i] << " " ;
    }

    selectionSort_des(arr,size);
    cout<<"\n After sorting: " ;
    for(int i =0; i<size ; i++){
        cout<< arr[i] << " " ;
    }
}
