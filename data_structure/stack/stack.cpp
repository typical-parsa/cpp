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

class STACK{
    private:
        int height;
        Node* top;
    
    public:
        STACK(){
            this->height = 0;
            this->top = nullptr;
        }  

        ~STACK(){
            while(this->top != nullptr){
                Node* temp_node = this->top;
                this->top = this->top->next;
                delete temp_node;
            }
        }

        void push_node(int value){
            Node* new_node = new Node(value);
            new_node->next = this->top;
            this->top = new_node;
            this->height++;
        }
};