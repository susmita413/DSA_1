# include <iostream>

using namespace std;

int binarySearch(int a[], int n, int data){

    int l,r,mid;
    l=0;
    r=n-1 ;
    
    while(l<=r){

        mid= (l+r)/2 ;

        if(data == a[mid]){
            return mid ;
        }

        else if(data > a[mid]){
            l= mid+1 ;
        }

        else {
            r= mid-1 ;
        }
    }

    return -1;
}




void  insertionSort (int a[], int n){

    for(int i=1; i<n ; i++){

        int temp= a[i];
        int j= i-1 ;

        while (j>=0 &&  a[j]> temp){

            a[j+1] = a[j];
            j-- ; 
        }

        a[j+1] = temp ;

    }

}



int main (){

    int arr[]= { 63,71,5,9,17,89,45,23,25,59,10,21,12,15,1,33,30};
    int len= sizeof(arr)/ sizeof(arr[0]);

    cout << " Before sorting: " << endl;
    for(int i=0; i<len; i++){
        cout << " " << arr[i] ;
    }

    insertionSort(arr,len);

    cout << endl << " after sorting: " << endl;
    for(int i=0; i<len; i++){
        cout << " " << arr[i] ;
    }

    int data ;
    cout << endl << " which number's place you want to know :  " ;
    cin >> data ;

    int index = binarySearch(arr,len, data);

    if(index== -1){
        cout << "number is not exist. again try" ;
    }
    else if(index>=0){
        cout << " it is in " << index+1 << "th position" ;
    }

 return 0;

}