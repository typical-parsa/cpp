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

class HT{
    private:
        int size;
        Node** DataMap;

    public:
        HT(int table_size){
            this->size = size;
            this->DataMap = new Node*[size];
            this->DataMap = new Node*[size];
            this->DataMap = new Node*[size];
            for(int i = 0 ; i < size ; i++){
                DataMap[i] = nullptr;
            }
        }

        void print_table(){
            for(int i = 0; i < this->size; i++) {
                cout << i << ":" << endl;
                if(this->DataMap[i]) {
                    Node* temp_node = DataMap[i];
                    while (temp_node != nullptr) {
                        cout << "   {" << temp_node->key << ", " << temp_node->value << "}" << endl;
                        temp_node = temp_node->next;
                    }
                }
            }
        }

        int hash_function(string key){
            int hash_value = 0;
            for(int i = 0 ; i < key.length(); i++){
                hash_value += (int(key[i]) * 31) % this->size;
            }
            return hash_value;
        }

        void set_value(string key, int value){
            int space_address = this->hash_function(key);
            Node* new_node = new Node(key, value);
            if(this->DataMap[space_address] == nullptr){
                this->DataMap[space_address] = new_node;
            }else{
                Node* temp_node = this->DataMap[space_address];
                while(temp_node != nullptr){
                    temp_node = temp_node->next;
                }
                temp_node->next = new_node;
            }
        }

        int get_value(string key){
            int space_address = this->hash_function(key);
            Node* temp_node = this->DataMap[space_address];
            while(temp_node != nullptr){
                if(temp_node->key == key){
                    return temp_node->value;
                }else{
                    temp_node = temp_node->next;
                }
            }
            return INT_MIN;
        }
};