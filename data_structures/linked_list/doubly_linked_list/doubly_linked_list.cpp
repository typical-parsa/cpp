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
            this->tail = nullptr;
            this->length = 0;
        }

        void print_list(){
            if (this->length == 0){
                return;
            }else{
                Node* temp_node = this->head;
                while (temp_node != nullptr){
                    cout << temp_node->value << " ";
                    temp_node = temp_node->next;
                }
                cout << endl;
            }
        }

        bool append_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->tail->next = new_node;
                new_node->before = this->tail;
                this->tail = new_node;
            }
            this->length++;
            return true;
        }

        bool delete_last_node(){
            if (this->length == 0){
                return false;
            }
            Node* temp_node = this->tail;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->tail = this->tail->before;
                this->tail->next = nullptr;
            }
            this->length--;
            delete temp_node;
            return true;
        }

        bool prepend_node(int value){
            Node* new_node = new Node(value);
            if (this->length == 0){
                this->head = new_node;
                this->tail = new_node;
            }else{
                this->head->before = new_node;
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
            return true;
        }

        bool delete_first_node(){
            if (this->length == 0){
                return false;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
                this->head->before = nullptr;
            }
            this->length--;
            delete temp_node;
            return true;
        }
};