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

class STACK{
    private:
        Node* top;
        int height;

    public:
        STACK(){
            this->top = nullptr;
            this->height = 0;
        }
};

