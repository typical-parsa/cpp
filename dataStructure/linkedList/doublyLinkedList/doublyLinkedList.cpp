#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* previous;

    Node(int value){
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        ~DoublyLinkedList(){
            while (this->head != nullptr){
                Node* tempNode this->head;
                this->head = this->head->next;
                delete tempNode;
            }
            this->tail = nullptr;
            this->length = 0;
        }

        bool appendNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                newNode->previous = this->tail;
                this->tail = newNode;
            }
            this->length++;
            return true;
        }

        bool deleteLastNode(){
            if (this->length == 0){
                return false;
            }
            Node* tempNode = this->tail;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->tail = this->tail-previous;
                this->tail->next = nullptr;
            }
            this->length--;
            delete tempNode;
            return true;
        }

        bool prependNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                newNode->next = this->head;
                this->head->previous = newNode;
                this->head = newNode;
            }
            this->length++;
            return true;
        }

        bool deleteFirstNode(){
            if (this->length == 0){
                return false;
            }
            Node* tempNode = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
                this->head->previous = nullptr;
            }
            this->length--;
            delete tempNode;
            return true;
        }
};


