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

        Node* get_node_by_index(int index){
            if (this->length == 0){
                return nullptr;
            }else if (index < 0 || index >= this->length){
                return nullptr;
            }else{
                Node* temp_node;
                if (this->length / 2 > index){
                    temp_node = this->head;
                    for (int i = 0 ; i < index ; i++){
                        temp_node = temp_node->next;
                    }
                }else{
                    temp_node = this->tail;
                    for (int i = this->length - 1 ; i > index ; i--){
                        temp_node = temp_node->before;
                    }
                }
                return temp_node;
            }
        }

        bool set_node_value(int index, int value){
            if (this->length == 0){
                return false;
            }else if (index < 0 || index >= this->length){
                return false;
            }else{
                Node* temp_node = this->get_node_by_index(index);
                if (temp_node != nullptr){
                    temp_node->value = value;
                    return true;
                }else{
                    return false;
                }
            }
        }

        bool insert_node(int index, int value){
            if (index < 0 || index > this->length){
                cout << "Invalid Index!" << endl;
                return false;
            }else if (index == 0){
                return this->prepend_node(value);
            }else if (index == this->length){
                return this->append_node(value);
            }else{
                Node* before_node = this->get_node_by_index(index - 1);
                if (before_node != nullptr){
                    Node* new_node = new Node(value);
                    Node* after_node = before_node->next;
                    before_node->next = new_node;
                    new_node->before = before_node;
                    new_node->next = after_node;
                    after_node->before = new_node;
                    this->length++;
                    return true;
                }else{
                    return false;
                }
            }
        }

        bool delete_node(int index){
            if (this->length == 0){
                cout << "List is empty!" << endl;
                return false;
            }else if (index < 0 || index >= this->length){
                cout << "Invalid Index!" << endl;
                return false;
            }else if (index == 0){
                return this->delete_first_node();
            }else if (index == this->length - 1){
                return this->delete_last_node();
            }else {
                Node* temp_node = this->get_node_by_index(index);
                if (temp_node != nullptr){
                    Node* before_node = temp_node->before;
                    Node* after_node = temp_node->next;
                    before_node->next = after_node;
                    after_node->before = before_node;
                    this->length--;
                    delete temp_node;
                    return true;
                }else{
                    return false;
                }

            }
        }
};