#include <iostream>

using namespace std;


struct Node{
    int vertex;
    int weight;
    Node* next;
};

class Graph{
    private:
        int vertexNumber;
        Node** adjacencyList;
        bool isDirected;
        bool isWeighted;
    
    public:
        Graph(int vertexNumber, bool isDirected, bool isWeighted){
            this->vertexNumber = vertexNumber;
            this->isDirected = isDirected;
            this->isWeighted = isWeighted;
            this->adjacencyList = new Node*[vertexNumber];
            for (int i = 0 ; i < this->vertexNumber){
                adjacencyList[i] = nullptr.
            }
        }
};