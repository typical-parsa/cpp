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

class singularLinkedList{
    private:
        Node* head;
        Node* tail;
        int lenght;

    public:
        singularLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->lenght;
        }

        ~singularLinkedList(){
            while (this->head != nullptr){
                Node* tempNode = this->head;
                this->head = this->head->next;
                delete tempNode;
            }
            this->tail = nullptr;
            this->lenght = 0;
        }
};