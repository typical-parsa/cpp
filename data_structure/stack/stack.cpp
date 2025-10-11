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
};