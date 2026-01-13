#include <iostream>
#include <climits>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;

        Node(string key, int value){
            this->value = value;
            this->key = key;
            this->next = nullptr;
        }
};

class hashTable{
    private:
        int size;
        Node** dataMap;
    
    public:
        hashTable(int tableSize){
            this->size = tableSize;
            this->dataMap = new Node*[size];
            for (int i = 0 ; i < size ; i++){
                this->dataMap[i] = nullptr;
            }
        }

        ~hashTable(){
            for (int i = 0 ; i < this->size ; i++){
                Node* currentNode = this->dataMap[i];
                while (currentNode != nullptr){
                    Node* tempNode = currentNode;
                    currentNode = currentNode->next;
                    delete tempNode;
                }
            }
            delete[] this->dataMap;
        }
};