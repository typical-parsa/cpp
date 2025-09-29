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
        Node* front;
        Node* rear;
        int length;

    public:
        QUEUE(){
            this->front = nullptr;
            this->rear = nullptr;
            this->length = 0;
        }

        ~QUEUE(){
            while (this->front != nullptr){
                Node* temp_node = this->front;
                this->front = this->front->next;
                delete temp_node;
            }
        }

        void print_queue(){
            if (this->length == 0){
                cout << "Queue is empty!" << endl;
                return;
            }else{
                Node* temp_node = this->front;
                cout << "Queue Items: " << endl << "Null <- ";
                while (temp_node != nullptr){
                    cout << temp_node->value << " <- ";
                    temp_node = temp_node->next;
                }
                cout << endl;
            }
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

        int dequeue_node(){
            if (this->length == 0){
                cout << "Queue is empty!" << endl;
                return INT_MIN;
            }else{
                Node* temp_node = this->front;
                int dequeued_value = temp_node->value;
                if (this->length == 1){
                    this->front = nullptr;
                    this->rear = nullptr;
                }else{
                    this->front = this->front->next;
                }
                delete temp_node;
                this->length--;
                return dequeued_value;
            }
        }
};