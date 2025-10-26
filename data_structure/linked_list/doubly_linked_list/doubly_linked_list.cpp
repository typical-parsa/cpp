#include <iostream>

using namespace std;

class Node{
    public: 
        int value;
        Node* next;
        Node* before;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->before = nullptr;
        }
};