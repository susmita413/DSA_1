
//
// Created by Sifat Ali on 12/1/2023.
//
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Edge {
public:
    int dis;
    Edge(int dis) {
        this->dis = dis;
    }
};

void Visited(int v, bool Array[], list<Edge> Graph[], stack<int> &Stack) {
    Array[v] = true;

    for (Edge e : Graph[v]) {
        int adjacentVertex = e.dis;
        if (!Array[adjacentVertex]) {
            Visited(adjacentVertex, Array, Graph, Stack);
        }
    }

    Stack.push(v);
}

void topoSort(list<Edge> Graph[], int size, int start) {
    bool* Array = new bool[size];
    for (int i = 0; i < size; i++) {
        Array[i] = false;
    }

    stack<int> Stack;

    for (int i = 0; i < size; i++) {
        if (!Array[i]) {
            Visited(i, Array, Graph, Stack);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }

    delete[] Array;
}

int main() {
    int v = 6;

    list<Edge> Graph[v];
    Graph[5].push_back(Edge(0));
    Graph[5].push_back(Edge(2));

    Graph[4].push_back(Edge(0));
    Graph[4].push_back(Edge(1));

    Graph[2].push_back(Edge(3));
    Graph[3].push_back(Edge(1));

    int start = 4;
    topoSort(Graph, v, start);

   return 0;
}