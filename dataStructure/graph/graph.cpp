#include <iostream>

using namespace std;

class Graph{
    private:
        int vertexNumber;
        int** adjacencyMatrix;
        bool isDirected;

    public:
        Graph(int vertices, bool isDirected){
            this->vertexNumber = vertices;
            this->adjacencyMatrix = new int*[vertexNumber];   
            this->isDirected = isDirected;
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
        void addEdge(int uNode, int vNode){
            if (uNode < 0 || vNode < 0 || uNode >= this->vertexNumber || vNode >= this->vertexNumber){
                return;
            }else{
                adjacencyMatrix[uNode][vNode] = 1;
                if (!isDirected){
                    adjacencyMatrix[vNode][uNode] = 1;
                }
            }
        }

        void removeEdge(int uNode, int vNode){
            if (uNode < 0 || vNode < 0 || uNode >= this->vertexNumber || vNode >= this->vertexNumber){
                return;
            }else{
                adjacencyMatrix[uNode][vNode] = 0;
                if (!isDirected){
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
    Graph* myGraph1 = new Graph(5, true);
    myGraph1->addEdge(0,1);
    myGraph1->printMatrix();
    cout << "--------------------------" << endl;
    Graph* myGraph2 = new Graph(5, false);
    myGraph2->addEdge(0,1);
    myGraph2->printMatrix();
}