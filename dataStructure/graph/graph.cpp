#include <iostream>

using namespace std;

class Graph{
    private:
        int vertexNumber;
        int** adjacencyMatrix;
        bool isDirected;
        bool isWeighted;

    public:
        Graph(int vertices, bool isDirected, bool isWeighted){
            this->vertexNumber = vertices;
            this->adjacencyMatrix = new int*[vertexNumber];   
            this->isDirected = isDirected;
            this->isWeighted = isWeighted;
            for(int i = 0; i < vertexNumber; i++) {
                this->adjacencyMatrix[i] = new int[vertexNumber];
            }
            for (int i = 0 ; i < vertexNumber ; i++){
                for (int j = 0 ; j < vertexNumber ; j++){
                    this->adjacencyMatrix[i][j] = 0;
                }
            }
        }
        ~Graph() {
            for(int i = 0; i < vertexNumber; i++) {
                delete[] adjacencyMatrix[i];
            }
            delete[] adjacencyMatrix;
        }
        void addEdge(int uNode, int vNode, int weight = 1){
            if (uNode < 0 || vNode < 0 || uNode >= this->vertexNumber || vNode >= this->vertexNumber){
                return;
            }else{
                if (this->isWeighted){
                    adjacencyMatrix[uNode][vNode] = weight;
                }else{
                    adjacencyMatrix[uNode][vNode] = 1;
                }
                if (!this->isDirected){
                    if (this->isWeighted){
                        adjacencyMatrix[vNode][uNode] = weight;
                    }else{
                        adjacencyMatrix[vNode][uNode] = 1;
                    }
                }
            }
        }

        void removeEdge(int uNode, int vNode){
            if (uNode < 0 || vNode < 0 || uNode >= this->vertexNumber || vNode >= this->vertexNumber){
                return;
            }else{
                adjacencyMatrix[uNode][vNode] = 0;
                if (!this->isDirected){
                    adjacencyMatrix[vNode][uNode] = 0;
                }
            }
        }

        void printMatrix(){
            cout << "Adjacency Matrix: " << endl;
            for (int i = 0 ; i < this->vertexNumber ; i++){
                for (int j = 0 ; j < this->vertexNumber ; j++){
                    cout << adjacencyMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph* weightedDirectional = new Graph(5, true, true);
    weightedDirectional->addEdge(0,1, 5);
    weightedDirectional->addEdge(2,3, 3);
    weightedDirectional->printMatrix();
    cout << "--------------------------" << endl;
    Graph* weightedUndirectional = new Graph(5, false, true);
    weightedUndirectional->addEdge(0,1, 5);
    weightedUndirectional->addEdge(2,3, 3);
    weightedUndirectional->printMatrix();
    cout << "--------------------------" << endl;
    Graph* unweightedDirectional = new Graph(5, true, false);
    unweightedDirectional->addEdge(0,1);
    unweightedDirectional->addEdge(2,3);
    unweightedDirectional->printMatrix();
    cout << "--------------------------" << endl;
    Graph* unweightedUndirectional = new Graph(5, false, false);
    unweightedUndirectional->addEdge(0,1);
    unweightedUndirectional->addEdge(2,3);
    unweightedUndirectional->printMatrix();
    cout << "--------------------------" << endl;
}