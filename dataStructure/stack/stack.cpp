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
                Node* tempNode = this->top;
                this->top = this->top->next;
                delete tempNode;
            }
            this->height = 0;
        }

        void printStack(){
            if (this->height == 0){
                return;
            }else{
                Node* tempNode = this->top;
                while (tempNode != nullptr){
                    cout << tempNode->value << " ";
                    tempNode = tempNode->next;
                }
                cout << ndl;
            }
        }

        bool pushNode(int value){
            Node* newNode = new Node(value);
            newNode->next = this->top;
            this->top = newNode;
            this->height++;
            return true;
        }

        int popNode(){
            if (this->height == 0){
                return INT_MIN;
            }
            Node* tempNode = this->top;
            int poppedValue = tempNode->value;
            this->top = this->top->next;
            this->height--;
            delete tempNode;
            return poppedValue;
        }
};

int main(){
    
}