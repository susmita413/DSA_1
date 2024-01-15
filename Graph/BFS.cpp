//BFS-- copy

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Edge {
public:
    int dis;
    Edge(int dis) {
        this->dis = dis;
    }
};

void BFS(list<Edge> Graph[], int start, int size) {
    bool *Array = new bool[size];

    for (int i = 0; i < size; i++) {
        Array[i] = false;
    }

    queue<int> q;
    Array[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (Edge e : Graph[current]) {
            int adjacentVertex = e.dis;
            if (!Array[adjacentVertex]) {
                Array[adjacentVertex] = true;
                q.push(adjacentVertex);
            }
        }
    }
    delete[] Array;
}

int main() {
    int v = 4;

    list<Edge> Graph[v];

    Graph[0].push_back(Edge(1));
    Graph[0].push_back(Edge(2));

    Graph[1].push_back(Edge(2));

    Graph[2].push_back(Edge(0));
    Graph[2].push_back(Edge(3));

    Graph[3].push_back(Edge(3));

    BFS(Graph, 0, v); 
    return 0;
}