#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;

        Node(int value){
            this->value = value;
            this->key = key;
            this->next = nullptr;
        }
};