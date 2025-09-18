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

class SLL{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        SLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        ~SLL(){
           while (this->head != nullptr){
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
            }
        }
};