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
