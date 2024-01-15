//Bubble sort Descending order with manual tracing every iteration

# include <iostream>
using namespace std;

void bubbleSortDesending(int a[],int n){
    int temp ;
    for(int i=0; i<n-1; i++){
        int flag = 0;
        for(int j=0 ; j<n-1-i; j++){
            if(a[j] < a[j+1]){
                temp= a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag=1;
                cout<< "temp= " <<temp << ", i= " << i << ", j= " << j << endl ;
            }
        }
        cout << " i= " << i  << endl ;
        if(flag== 0){
            break ;
        }
    }
}

int main(){

    int arr[]= {1,2,3,4};
    int len = sizeof(arr)/sizeof(arr[0]);

    cout << "before sorting: " ;
    for(int i=0; i<len; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;

    bubbleSortDesending(arr,len);
    cout<< endl << " after descending oreder sort: " ;
    for(int i=0; i<len; i++){
        cout << " " << arr[i]  ;
    }
    return 0;
}