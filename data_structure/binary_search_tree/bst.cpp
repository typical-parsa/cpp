#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value){
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
};

class BST{
    public:
        Node* root;
        BST(){
            this->root = nullptr;
        }

        bool insert_node(int value){
            Node* new_node = new Node(value);
            if (this->root == nullptr){
                this->root = new_node;
                return true;
            }
            Node* temp_node = this->root;
            while (true){
                if (new_node->value == temp_node->value){
                    delete temp_node;
                    return false;
                }
                if (new_node->value < temp_node->value){
                    if (temp_node->left == nullptr){
                        temp_node->left = new_node;
                        return true;
                    }
                    temp_node = temp_node->left;
                }else{
                    if (temp_node->right == nullptr){
                        temp_node->right = new_node;
                        return true;
                    }
                    temp_node = temp_node->right;
                }
            }
        }

        bool contains_node(int value){
            if (this->root == nullptr){
                cout << "Tree is empty!" << endl;
                return false;
            }else{
                Node* temp_node = this->root;
                while (temp_node != nullptr){
                    if (value < temp_node->value){
                        temp_node = temp_node->left;
                    }else if (value > temp_node->value){
                        temp_node = temp_node->right;
                    }else{
                        return true;
                    }
                }
                return false;
            }
        }
};