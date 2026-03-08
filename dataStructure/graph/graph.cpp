#include <iostream>

using namespace std;

class Graph{
    private:
        int vertexNumber;
        int** adjacencyList;

    public:
        Graph(int vertices){
            this->vertexNumber = vertices;
            this->adjacencyList = new int*[vertexNumber];   
            for(int i = 0; i < vertexNumber; i++) {
                this->adjacencyList[i] = new int[vertexNumber];
            }
            for (int i = 0 ; i < vertexNumber ; i++){
                for (int j = 0 ; j < vertexNumber ; j++){
                    this->adjacencyList[i][j] = 0;
                }
            }
        }
        ~Graph() {
            for(int i = 0; i < vertexNumber; i++) {
                delete[] adjacencyList[i];
            }
            delete[] adjacencyList;
        }
        void addEdge(int uNode, int vNode){
            if (uNode < 0 || vNode < 0 || uNode >= this->vertexNumber || uNode >= this->vertexNumber){
                return;
            }else{
                adjacencyList[uNode][vNode] = 1;
                adjacencyList[vNode][uNode] = 1;
            }
        }

        void removeEdge(int uNode, int vNode){
            adjacencyList[uNode][vNode] = 0;
            adjacencyList[vNode][uNode] = 0;
        }

        void printMatrix(){
            cout << "Adjacency Matrix: " << endl;
            for (int i = 0 ; i < this->vertexNumber ; i++){
                for (int j = 0 ; j < this->vertexNumber ; j++){
                    cout << adjacencyList[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){

}