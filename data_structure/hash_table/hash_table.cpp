#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        string key;
        Node* next;

        Node(int value){
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
};