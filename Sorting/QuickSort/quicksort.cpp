#include <iostream>
using namespace std;

//void swap(int a, int b);

int partition(int a[], int lb, int ub){
    int temp;
    int pivot = a[lb] ;
    int start = lb ;
    int end = ub ;
    while(start < end ){
        while(a[start] <= pivot ){
            start++ ;
        }
        while(a[end] >pivot ){
            end-- ;
        }
        if(start< end){
           // swap(a[start], a[end]);
            temp = a[end] ;
            a[end] = a[start];
            a[start] = temp ;
        }
    }

    //swap(a[lb], a[end]);
    temp = a[end] ;
    a[end] = a[lb];
    a[lb] = temp ; 
    return end ;
}

void QuickSort(int a[], int lb, int ub){

    if(lb< ub){
        int loc = partition(a,lb,ub);
        QuickSort(a,lb,loc-1);
        QuickSort(a,loc+1,ub);

    }
}

int main(){

    int arr[]={7,6,10,5,9,2,1,15,7};
    int len = sizeof(arr)/sizeof(arr[0]);

    cout << "before sorting : " << endl;
    for(int i=0; i<len ;i++){
        cout << " " << arr[i] ;

    }

    QuickSort(arr,0,len-1);

    cout << "\n after sorting : " << endl;
    for(int i=0; i<len ;i++){
        cout << " " << arr[i] ;

    }

    return 0;
}