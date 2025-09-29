#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
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

        void enqueue_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->front = new_node;
                this->rear = new_node;
            }else{
                this->rear->next = new_node;
               this->rear = new_node;
            }
            this->length++;
        }
};