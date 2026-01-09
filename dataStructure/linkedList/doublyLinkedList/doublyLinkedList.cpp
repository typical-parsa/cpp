#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class doublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        doublyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }
        ~doublyLinkedList(){
            while (this->head != nullptr){
                Node* tempNode = this->head;
                this->head = this->head->next;
                delete tempNode;
            }
            this->tail = nullptr;
            this->length = 0;
        }
};