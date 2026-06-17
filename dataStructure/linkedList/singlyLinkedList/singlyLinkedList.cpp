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
                Node* tempNode = this->head;
                this->head = this->head->next;
                delete tempNode;
            }
            this->tail = nullptr;
            this->length = 0;
        }

        void printList(){
            if (this->length == 0){
                return;
            }
            Node* tempNode = this->head;
            while (tempNode != nullptr){
                cout << tempNode->value << " ";
                tempNode = tempNOde->next;
            }
            cout << endl;
        }

        bool appendNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->length++;
            return true;
        }

        bool deleteLastNode(){
            if (this->length == 0){
                return false;
            }
            Node* tempNode = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* previousNode = tempNode;
                while (tempNode->next != nullptr){
                    previousNode = tempNode;
                    tempNode = tempNode->next;
                }
                this->tail = previousNode;
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
            }
            this->length--;
            delete tempNode;
            return true;
        }

        bool insertNodeAt(int index, int value){
            if (index < 0 || index > this->length){
                return false;
            }
            if (index == 0){
                return this->prependNode(value);
            }
            if (index == this->length){
                return this->appendNode(value);
            }

            Node* newNode = new Node(value);
            Node* tempNode = this->head;
            for (int i = 0 ; i < index - 1; i++){
                tempNode = tempNode->next;
            }
            newNode->next = tempNode->next;
            tempNode->next = newNode;
            this->length++;
            return true;
        }
};