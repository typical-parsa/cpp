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

        void printList(){
            if (this->length = 0){
                return;
            }else{
                Node* tempNode = this->head;
                while (tempNode != nullptr){
                    cout << tempNode->value << " ";
                    tempNode = tempNode->next;
                }
                cout << endl;
            }
        }

        bool appendNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                newNode->prev = this->tail;
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
                this->tail = this->tail->prev;
                this->tail->next = nullptr;
            }
            this->length--;
            delete tempNode;
            return true;
        }


};