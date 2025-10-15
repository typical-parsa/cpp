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

        void enqueue_node(int value){
            Node* new_node = new Node(value);
            if(this->length == 0){
                this->front = new_node;
                this->rear = new_node;
            }else{
                this->rear->next = new_node;
                this->rear = new_node;
            }
            this->length++;
        }

        int dequeue_node(){
            if(this->length == 0){
                cout << "Queue is empty!" << endl;
                return INT_MIN;
            }
            Node* dequeued_node = this->front;
            int dequequeued_value = dequeued_node->value;
            if(this->length == 1){
                this->front = nullptr;
                this->rear = nullptr;
            }else{
                this->front = this->front->next;
            }
            this->length--;
            delete dequeued_node;
            return dequequeued_value;
        }
};