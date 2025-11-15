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

class SLL{
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        SLL(){
            this->head = nullptr;
            this->tail = nullptr;
            this->length = 0;
        }

        ~SLL(){
            while (this->head != nullptr){
                Node* temp_node = this->head;
                this->head = this->head->next;
                delete temp_node;
            }
        }

        void print_list(){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return;
            }else{
                Node* temp_node = this->head;
                while (temp_node != nullptr){
                    cout << temp_node->value << " ";
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
                this->tail = new_node;
            }
            this->length++;
            return true;
        }

        bool delete_last_node(){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return false;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                Node* previous_node = temp_node;
                while (temp_node->next != nullptr){
                    previous_node = temp_node;
                    temp_node = temp_node->next;
                }
                previous_node->next = nullptr;
                this->tail = previous_node;
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
                new_node->next = this->head;
                this->head = new_node;
            }
            this->length++;
            return true;
        }

        bool delete_first_node(){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return false;
            }
            Node* temp_node = this->head;
            if (this->length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
            }
            this->length--;
            delete temp_node;
            return true;
        }

        Node* get_node_by_index(int index){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return nullptr;
            }else{
                if (index < 0 || index >= this->length){
                    cout << "Invalid Index!" << endl;
                    return nullptr;
                }else{
                    Node* temp_node = this->head;
                    for (int i = 0 ; i < index ; i++){
                        temp_node = temp_node->next;
                    }
                    return temp_node;
                }
            }
        }
};