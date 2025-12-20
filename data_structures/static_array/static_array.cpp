#include <iostream>
using namespace std;

bool append(int arr[], int value, int &size, int capacity);

int main(){
    int arr[100];
    int size = 0;
    int capacity = 100;
}

void print_array(int arr[], int size){
    for (int i = 0 ; i < size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool append(int arr[], int value, int &size, int capacity){
    if (size >= capacity){
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}

bool prepend(int arr[], int value, int &size, int capacity){
    if (size >= capacity){
        return false;
    }
    for (int i = size ; i > 0 ; i--){
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    return true;

}

bool delete_last(int arr[], int &size){
    if (size == 0){
        return false;
    }
    size--;
    return true;
}

bool delete_first(int arr[], int &size){
    if (size == 0){
        return false;
    }
    for (int i = 0 ; i < size - 1; i++){
        arr[i] = arr[i + 1];
    }
    size--;
    return true;
}

bool insert_at(int arr[], int &size, int capacity, int index, int value){
    if (size >= capacity ){
        return false;
    }else if (index > size){
        return false;
    }else{
        for (int i = size ; i > index ; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
        return true;
    }
}

bool delete_at(int arr[], int &size, int index){
    if (size == 0){
        return false;
    }else if (index < 0 || index >= size){
        return false;
    }else{
        for (int i = index ; i < size-1 ; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return true;
    }
}
