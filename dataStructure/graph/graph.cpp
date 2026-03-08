#include <iostream>

using namespace std;

class Graph{
    private:
        int vertexNumber;
        int adjacencyList[100][100];

    public:
        Graph(int vertices){
            this->vertexNumber = vertices;
            for (int i = 0 ; i < vertexNumber ; i++){
                for (int j = 0 ; j < vertexNumber ; j++){
                    this->adjacencyList[i][j] = 0;
                }
            }
        }
};