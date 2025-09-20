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

        void print_list(){
            if (this->lenght == 0){
                cout << "List is empty!" << endl;
                return;
            }else{
                Node* temp_node = this->head;
                cout << "List Items: " << endl << "Null <->";
                while (temp_node != nullptr){
                    cout << temp_node->value << " <-> ";
                    temp_node = temp_node->next;
                }
                cout << "Null" << endl;
            }
        }

        void append_node(int value){
            Node* new_node = new Node(value);
            if (this->lenght == 0){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->tail->next = new_node;
                new_node->previous = this->tail;
                this->tail = new_node;
            }
            this->lenght++;
        }

        void delete_last_node(){
            if (this->lenght == 0){
                cout << "List is empty!" << endl;
                return;
            }
            Node* temp_node = this->tail;
            if (this->lenght == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->tail = this->tail->previous;
                this->tail->next = nullptr;
            }
            delete temp_node;
            this->lenght--;
        }
};