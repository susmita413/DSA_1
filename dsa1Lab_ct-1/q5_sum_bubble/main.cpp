# include <iostream>
using namespace std;

int sum(int a[],int len, int num){

    int add=0;

  for(int i=len-1; i>=(len-num) ;i--){
       add=add+a[i];
  }

return add;

}


void bubbleSort(int a[], int n){

    int temp ;

    

    for(int i=0; i<n-1 ; i++){

        for(int j=0; j<n-1-i; j++){

            if(a[j]> a[j+1]){
                temp= a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
               
            }
        }
    }


}


int main(){
int arr[]= {4,1,2,7,6,5};
int len =sizeof(arr)/ sizeof(arr[0]);

 bubbleSort(arr,len);

//for(int i=0; i<len; i++){
//    cout<< arr[i];
//}
cout<< endl << "enter:  " ;

int num;
cin >> num;
int add= sum(arr,len , num );

cout<< add;
return 0;


}

