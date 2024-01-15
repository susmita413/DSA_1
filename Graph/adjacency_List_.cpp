// directed //undirected //much better
// Created by User on 12/6/2023.
//
#include<iostream>
#include<list>
using namespace std;

class Adjacency_list{
public:
    int node;
    Adjacency_list(int node){
        this->node = node ;
    }
};

void addEdge(list<Adjacency_list>arr[], int start, int node){
    arr[start].push_back(node);
  //  arr[node].push_back(start); // for undirected graph
}

void display(list<Adjacency_list>arr[], int n){
    for(int i =0 ; i<n ; i++){
       cout<<"vertex[" << i << "] : "  ;
       for(Adjacency_list e : arr[i]){
           cout<< " -> " << e.node ;
       }
       cout<< endl ;
    }
}

int main(){
    int n = 5;
    list<Adjacency_list> arr[n];
    addEdge(arr,0,1);
    addEdge(arr,0,2);
    addEdge(arr,1,3);
    addEdge(arr,2,1);
    addEdge(arr,2,3);

    addEdge(arr,3,4);
    addEdge(arr,4,0);
    addEdge(arr,4,2);



    display(arr,n);
}

