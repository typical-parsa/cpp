#include <iostream>
#include <climits>

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
        Node* rear;
        Node* front;
        int length;
    
    public:
        QUEUE(){
            this->rear = nullptr;
            this->front = nullptr;
            this->length = 0;
        }

        ~QUEUE(){
            while(this->front != nullptr){
                Node* temp_node = this->rear;
                this->rear = this->rear->next;
                delete temp_node;
            }
        }
};