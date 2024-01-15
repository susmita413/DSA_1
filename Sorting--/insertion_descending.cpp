//
// Created by User on 11/22/2023.
//
// descending order insertion Sort WITH MANUAL tracing


#include <iostream>
using namespace std;

void  insertionSort (int a[], int n){
    for(int i=1; i<n ; i++){
        int temp= a[i];
        int j= i-1 ;
        while (j>=0 &&  a[j]< temp){
            a[j+1] = a[j];
            cout << endl << "IN while LOOP: temp: " << temp << " ,i= " << i << " , j= " << j << endl ;
            j-- ;
        }
        a[j+1] = temp ;
        cout << endl << " temp: " << temp << " ,i= " << i << " , j= " << j << endl ;
    }
}


int main()
{
    int arr[]={40,30,20,15,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    cout << "before sorting : " << endl;
    for(int i=0; i<len ;i++){
        cout << " " << arr[i] ;

    }
    insertionSort(arr,len);
    cout << endl;
    cout << " after sorting : " << endl;
    for(int i=0; i<len ;i++){
        cout << " " << arr[i] ;

    }
    return 0;
}
