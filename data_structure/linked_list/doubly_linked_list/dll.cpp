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

class DLL{
    private:
        Node* head;
        Node* tail;
        int lenght;

    public:
        DLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->lenght = 0;
        }

        ~DLL(){
           while (this->head != nullptr){
                Node* temp = this->head;
                this->head = this->head->next;
                delete temp;
            }
        }
};