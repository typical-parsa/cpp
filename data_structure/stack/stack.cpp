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

        void print_stack(){
            if (this->height == 0){
                cout << "Stack is empty!" << endl;
                return;
            }else{
                Node* temp_node = this->top;
                while (temp_node != nullptr){
                    cout << temp_node->value << endl;
                    temp_node = temp_node->next;
                }
            }
        }

        bool push_node(int value){
            Node* new_node = new Node(value);
            new_node->next = this->top;
            this->top = new_node;
            this->height++;
            return true;
        }

        int pop_node(){
            if (this->height == 0){
                cout << "Stack is empty!" << endl;
                return INT_MIN;
            }
            Node* temp_node = this->top;
            int popped_value = temp_node->value;
            this->top = this->top->next;
            this->height--;
            delete temp_node;
            return popped_value;
        }
};

int main(){
    
}