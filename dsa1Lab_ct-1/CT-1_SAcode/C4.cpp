#include<iostream>
using namespace std;

int main(){
    int arr[]={4,1,2,7,6,5};
    int n = sizeof(arr) / sizeof(arr[0]);


   int max=0;

    for(int i = 0; i < n-1; i++){
         max = i;

        for(int j = i+1; j < n; j++)
        {
            if(arr[j] > arr[max])
                max = j;
        }


        if(max != i){
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }

    for(int i = 0; i<n; i++){
            cout << arr[i] << " ";

    }

    cout<<endl;

    int p=arr[max];
    int result=0;
    for(int i = 0; i<n; i++){
        if(arr[i]==p){
                   p--;
               }
        else{
            result=i;
        }
    }

    cout<< result;

    return 0;
}