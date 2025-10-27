#include <iostream>
#include <climits>

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

class Stack{
    private:
        Node* top;
        int height;

    public:
        Stack(){
            this->top = nullptr;
            this->height = 0;
        }

        ~Stack(){
            while (this->top != nullptr){
                Node* temp_node = this->top;
                this->top = this->top->next;
                delete temp_node;
            }
        }
};