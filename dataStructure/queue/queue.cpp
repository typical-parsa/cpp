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

class Queue{
    private:
        Node* front;
        Node* rear;
        int length;

    public:
        Queue(){
            this->front = nullptr;
            this->rear = nullptr;
            this->length = 0;
        }

        ~Queue(){
            while (this->front != nullptr){
                Node* tempNode = this->front;
                this->front = this->front->next;
                delete tempNode;
            }
            this->rear = nullptr;
            this->length = 0;
        }

        void printQueue(){
            if (this->length == 0){
                return;
            }else{
                Node* tempNode = this->front;
                while (tempNode != nullptr){
                    cout << tempNode->value << " ";
                    tempNode = tempNode->next;
                }
                cout << endl;
            }
        }

        bool enqueueNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->front = newNode;
                this->rear = newNode;
            }else{
                this->rear->next = newNode;
                this->rear = newNode;
            }
            this->length++;
            return true;
        }

        int dequeueNode(){
            if (this->length == 0){
                return INT_MIN;
            }
            Node* tempNode = this->front;
            int dequeuedValue = tempNode->value;
            if (this->length == 1){
                this->front = nullptr;
                this->rear = nullptr;
            }else{
                this->front = this->front->next;
            }
            delete tempNode;
            this->length--;
            return dequeuedValue;
        }
};

int main(){

}