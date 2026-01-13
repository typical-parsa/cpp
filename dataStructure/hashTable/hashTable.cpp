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

        int hashFunction(string key){
            int hashedValue = 0;
            for (int i = 0 ; i < key.length() ; i++){
                hashedValue += ((int(key[i]) * 31) % this->size);
            }
            return hashedValue;
        }
    
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

        bool setValue (string key, int value){
            int spaceAddress = this->hashFunction(key);
            Node* newNode = new Node(key, value);
            if (this->dataMap[spaceAddress] == nullptr){
                this->dataMap[spaceAddress] = newNode;
                return true;
            }else{
                Node* tempNode = this->dataMap[spaceAddress];
                Node* prevNode = nullptr;
                while (tempNode != nullptr){
                    if (tempNode->key == key){
                        tempNode->value = value;
                        delete newNode;
                        return true;
                    }
                    prevNode = tempNode;
                    tempNode = tempNode->next;
                }
                prevNode->next = newNode;
                return true;
            }
        }

        int getValue(string key){
            int spaceAddress = this->hashFunction(key);
            Node* tempNode = this->dataMap[spaceAddress];
            while (tempNode != nullptr){
                if (tempNode->key == key){
                    return tempNode->value;
                }
                tempNode = tempNode->next;
            }
            return INT_MIN;
        }
};