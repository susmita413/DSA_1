#include <iostream>

using namespace std;

void selectionSort(int a[], int n){

     int temp ;

    for(int i=0; i<(n-1); i++){

        int min= i ;
        for(int j=i+1; j<n; j++){

            if(a[j]< a[min]){
                min = j ;
            }
        }

        if(min != i){
            temp = a[i];
            a[i]= a[min];
            a[min] = temp ;
        }
    }


}

int main()
{
    int arr[] = {8,10,7,5};
    int len= sizeof(arr)/ sizeof(arr[0]);
    cout << "Before sorting: " << endl;
    for(int i=0; i<len ; i++){
        cout << arr[i] << " " ;
    }

    selectionSort(arr, len);

    cout << endl <<  "After sorting : " << endl ;
    for(int i=0 ; i<len ; i++){
        cout << arr[i] << " " ;
    }


    return 0;

}
