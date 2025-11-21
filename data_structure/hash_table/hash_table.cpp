#include <iostream>
#include <climits>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;

        Node(string key, int value){
            this->value = value;
            this->key = key;
            this->next = nullptr;
        }
};

class Hash_table{
    private:
        int size;
        Node** data_map;

    public:
        Hash_table(int table_size){
            this->size = table_size;
            this->data_map = new Node*[size];
            for (int i = 0 ; i < size; i++){
                this->data_map[i] = nullptr;
            }
        }

        ~Hash_table(){
            for (int i = 0 ; i < this->size ; i++){
                Node* current_node = this->data_map[i];
                while (current_node != nullptr){
                    Node* temp_node = current_node;
                    current_node = current_node->next;
                    delete temp_node;
                }
            }
            delete[] this->data_map;
        }

        int hash_function(string key){
            int hashed_value = 0;
            for (int i = 0 ; i < key.length() ; i++){
                hashed_value += ((int(key[i]) * 31) % this->size);
            }
            return hashed_value;
        }

        bool set_value(string key, int value){
            int space_address = this->hash_function(key);
            Node* new_node = new Node(key, value);
            if (data_map[space_address] == nullptr){
                data_map[space_address] = new_node;
                return true;
            }else{
                Node* temp_node = data_map[space_address];
                Node* previous = nullptr;
                while (temp_node != nullptr){
                    if (temp_node->key == key){
                        temp_node->value = value;
                        delete new_node;
                        return true;
                    }
                    previous = temp_node;
                    temp_node = temp_node->next;
                }
                previous->next = new_node;
                return true;
            }
        }

        int get_value(string key){
            int space_address = this->hash_function(key);
            Node* temp_node = this->data_map[space_address];
            while (temp_node != nullptr){
                if (temp_node->key == key){
                    return temp_node->value;
                }else{
                    temp_node = temp_node->next;
                }
            }
            return INT_MIN;
        }
};