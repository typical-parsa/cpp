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

        bool prependNode(int value){
            Node* newNode = new Node(value);
            if (this->length == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->head->prev = newNode;
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
                this->head->prev = nullptr;
            }
            this->length--;
            delete tempNode;
            return true;
        }

        Node* getNodeByIndex(int index){
            if (this->length == 0){
                return nullptr;
            }else if (index < 0 || index >= this->length){
                return nullptr;
            }else{
                Node* tempNode;
                if (this->length / 2 > index){
                    tempNode = this->head;
                    for (int i = 0 ; i < index ; i++){
                        tempNode = tempNode->next;
                    }
                }else{
                    tempNode = this->tail;
                    for (int i = this->length - 1 ; i > index ; i--){
                        tempNode = tempNode->prev;
                    }
                }
                return tempNode;
            }
        } 

        bool setNodeValueByIndex(int index, int value){
            if (this->length == 0){
                return false;
            }else if (index < 0 || index >= this->length){
                return false;
            }else{
                Node* tempNode = this->getNodeByIndex(index);
                if (tempNode != nullptr){
                    tempNode->value = value;
                    return true;
                }else{
                    return false;
                }
            }
        }

        bool insertNode(int index, int value){
            if (index < 0 || index > this->length){
                return false;
            }else if (index == 0){
                return this->prependNode(value);
            }else if (index == this->length){
                return this->appendNode(value);
            }else{
                Node* prevNode = this->getNodeByIndex(index - 1);
                if (prevNode != nullptr){
                    Node* newNode = new Node(value);
                    Node* nextNode = prevNode->next;
                    prevNode->next = newNode;
                    newNode->prev = prevNode;
                    newNode->next = nextNode;
                    nextNode->prev = newNode;
                    this->length++;
                    return true;
                }else{
                    return false;
                }
            }
        }

        bool deleteNode(int index){
            if (this->length == 0){
                return false;
            }else if (index > 0 || index >= this->length){
                return false;
            }else if (index == 0){
                return this->deleteFirstNode();
            }else if (index == this->length - 1){
                return this->deleteLastNode();
            }else{
                Node* tempNode = this->getNodeByIndex(index);
                if (tempNode != nullptr){
                    Node* prevNode = tempNode->prev;
                    Node* nextNode = tempNode->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    this->length--;
                    delete tempNode;
                    return true;
                }else{
                    return false;
                }
            }
        }
};

int main(){
    
}