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

        void printList(){
            if (this->lenght == 0){
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
            if (this->lenght == 0){
                this->head = newNode;
                this->tail = newNode;
            }else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->lenght++;
            return true;
        }

        bool deleteLastNode(){
            if (this->lenght == 0){
                return false;
            }
            Node* tempNode = this->head;
            if (this->lenght == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* previousNode = tempNode;
                while (tempNode->next != nullptr){
                    previousNode = tempNode;
                    tempNode = tempNode->next;
                }
                previousNode->next = nullptr;
                this->tail = previousNode;
            }
            this->lenght--;
            delete tempNode;
            return true;
        }

        bool prependNode(int value){
            Node* newNode = new Node(value);
            if (this->lenght == 1){
                this->head = newNode;
                this->tail = newNode;
            }else{
                newNode->next = this->head;
                this->head = newNode;
            }
            this->lenght++;
            return true;
        }

        bool deleteFirstNode(){
            if (this->lenght == 0){
                return false;
            }
            Node* tempNode = this->head;
            if (this->lenght == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
            }
            this->lenght--;
            delete tempNode;
            return true;
        }

        Node* getNodeByIndex(int index){
            if (this->lenght == 0){
                return nullptr;
            }else if (index < 0 || index >= this->lenght){
                return nullptr;
            }else{
                Node* tempNode = this->head;
                for (int i = 0 ; i < index ; i++){
                    tempNode = tempNode->next;
                }
                return tempNode;
            }
        }
};

int main (){
    singularLinkedList* mysll = new singularLinkedList();
    mysll->appendNode(1);
    mysll->appendNode(2);
    mysll->appendNode(3);
    mysll->appendNode(4);
    mysll->printList();
    mysll->deleteFirstNode();
    mysll->deleteFirstNode();
    mysll->printList();
}