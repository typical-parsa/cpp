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

        bool AppendNode(int value){
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

        bool DeleteLastNode(){
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

        bool PrependNode(int value){
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

        bool DeleteFirstNode(){
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

        Node* GetNodeByIndex(int index){
            if (this->length == 0){
                return nullptr;
            }
            if (index < 0 || index >= this->length){
                return false;
            }
            Node* tempNode;
            if (this->length / 2 > index){
                tempNode = this->head;
                for (int i = 0 ; i < index ; i++){
                    tempNode = tempNode->next;
                }
            }else{
                tempNode = this->tail;
                for (int i = this->length - 1 ; i > index ; i--){
                    tempNode = tempNode->previous;
                }
            }
        return tempNode;        
        }

        bool SetNodeValueByIndex(int index, int value){
            if (this->length == 0){
                return false;
            }
            if (index < 0 || index >= this->length){
                return false;
            }
            Node* tempNode = this->GetNodeByIndex(index);
            tempNode->value = value;
            return true;
        }
};


