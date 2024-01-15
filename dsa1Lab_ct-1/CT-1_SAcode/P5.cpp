#include <iostream>
using namespace std;

void swap(int a, int b, int arr[]) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main() {
    int arr[] = {4,1,2,7,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int p;
   cin>>p;


    int flag=0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(j, j + 1, arr);
                flag++;
            }
        }
        if(flag==0){
            break;
        }
    }


    int sum=0;

    for (int i = 0; i<p; i++) {
        if(p>=i) {
           sum = sum + arr[i];
        }
        else{
            break;
        }
    }

    cout<<sum;




    return 0;
}