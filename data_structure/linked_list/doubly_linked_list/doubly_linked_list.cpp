#include <iostream>

using namespace std;

class Node{
    public: 
        int value;
        Node* next;
        Node* before;

        Node(int value){
            this->value = value;
            this->next = nullptr;
            this->before = nullptr;
        }
};

class DLL{
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        ~DLL(){
            while (this->head != nullptr){
                Node* temp_node = this->head;
                this->head = this->head->next;
                delete temp_node;
            }
        }
};