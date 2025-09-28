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

        void prepend_node(int value){
            Node* new_node = new Node(value);
            if (this->lenght == 0){
                this->head = new_node;
                this->tail = new_node;
            }else{
                new_node->next = this->head;
                this->head->previous = new_node;
                this->head = new_node;
            }
            this->lenght++;
        }

        void delete_first_node(){
            if (this->lenght == 0){
                cout << "List is empty!" << endl;
                return;
            }
            Node* temp_node = this->head;
            if (this->lenght == 0){
                this->head = nullptr;
                this->tail = nullptr;
            }else{
                this->head = this->head->next;
                this->head->previous = nullptr;
            }
            delete temp_node;
            this->lenght--;
        }

        Node* get_node_by_index(int index){
            if (this->lenght == 0){
                cout << "List is empty!" << endl;
                return nullptr;
            }else if (index < 0 || index >= this->lenght == 0){
                cout << "Invalid Index!" << endl;
                return nullptr;
            }else {
                if (index < this->lenght / 2){
                    Node* temp_node = this->head;
                    for (int i = 0 ; i < index ; i++){
                        temp_node = temp_node->next;
                    }
                    return temp_node;
                }else{
                    Node* temp_node = this->tail;
                    for (int i = this->lenght - 1 ; i > index ; i--){
                        temp_node = temp_node->previous;
                    }
                    return temp_node;
                }
            }
        }
};