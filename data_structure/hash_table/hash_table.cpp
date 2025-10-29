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
            for (int i = 0 ; i < size ; i++){
                this->data_map[i] = nullptr;
            }
        }

        ~Hash_table(){
            delete[] this->data_map;
        }

        int hash_function(string key){
            int hashed_value = 0;
            for (int i = 0 ; i < key.length(); i++){
                hashed_value += ((int(key[i]) * 31) % this->size);
            }
            return hashed_value;
        }
};