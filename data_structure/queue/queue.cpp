#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
};

class QUEUE{
    private:
        Node* front;
        Node* rear;
        int length;

    public:
        QUEUE(){
            this->front = nullptr;
            this->rear = nullptr;
            this->length = 0;
        }
};