// directed graph
// Created by User on 11/28/2023.
//

#include<iostream>
#include<list>
using namespace std;

class Adjacency_List{
public:
    int start_node;
    int nodes;
    Adjacency_List(int start_node, int nodes){
        this->start_node = start_node;
        this->nodes = nodes;
    }
};

void display(list<Adjacency_List> arr[] , int n){

    for(int i=0; i<n; i++){
        cout<< "vertices [" << i << "] : " ;
        for(Adjacency_List e : arr[i]){
            cout << "{" << e.start_node << "-> " <<e.nodes << "} ";
        }
        cout<< endl;
    }
}

int main(){
    int n= 5;
    list<Adjacency_List> arr[n];
    arr[0].push_back(Adjacency_List(0,1));
    arr[0].push_back(Adjacency_List(0,2));

    arr[2].push_back(Adjacency_List(2,1));
    arr[2].push_back(Adjacency_List(2,3));

    arr[3].push_back(Adjacency_List(3,4));
    arr[4].push_back(Adjacency_List(4,2));

    display(arr,n);

}
