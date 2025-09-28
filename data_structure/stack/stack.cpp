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
        Node* top;
        int height;

    public:
        STACK(){
            this->top = nullptr;
            this->height = 0;
        }

        void push_node(int value){
            if (this->height == 0){
                cout << "Stack is empty!" << endl;
                return;
            }else{
                Node* new_node = new Node(value);
                new_node->next = this->top;
                this->top = new_node;
                this->height++;
            }
        }
};

