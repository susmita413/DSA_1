//Bubble sort Ascending order with manual-trace every iteration//
#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    int temp ;
    for(int i=0; i<n-1 ; i++){
        int flag=0 ;
        for(int j=0; j<n-1-i; j++){
            if(a[j]> a[j+1]){
                temp= a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
                cout << endl <<"temp= " << temp << ", i= " << i << ", j= " << j << endl ;
            
               flag=1;
            }
        }
        cout << endl <<"after every inner LOOP: temp= " << temp << ", i= " << i << endl ;
        if(flag==0 ){
            break ;
        }
    }
}


int main()
{
    int arr[]= {5,4,3,2,1};
    int len= sizeof(arr)/sizeof(arr[0]);

    cout << "before sorting: " ;
    for(int i=0; i<len; i++){
        cout << arr[i] << " " ;
    }

    bubbleSort(arr,len);

    cout << endl << " After sorting: " ;
    for(int i=0; i<len; i++){
        cout << arr[i] << " " ;
    }
    return 0;
}
