# include <iostream>
using namespace std;

int linearSearch(int a[],int n,int data){

    int i, found=0 ;

    for(i=0; i<n; i++){

        if(a[i] == data){
            found=1 ;
             return i;
        }
    }

/*   if(found==0){
        return -1;
    }
*/
     
     return -1;
    

}

int main (){

    int arr[]= { 63,71,5,9,17,89,45,23,25,59,10,21,12,15,1,33,30};
    int len= sizeof(arr)/ sizeof(arr[0]);

    cout << " Before sorting: " << endl;
    for(int i=0; i<len; i++){
        cout << " " << arr[i] ;
    }

   

    int data ;
    cout << endl << " which number's place you want to know :  " ;
    cin >> data ;

    int index = linearSearch(arr,len, data);

    if(index== -1){
        cout << "number is not exist. again try" ;
    }
    else if(index>=0){
        cout << " it is in " << index+1 << "th position" ;
    }

 return 0;

}