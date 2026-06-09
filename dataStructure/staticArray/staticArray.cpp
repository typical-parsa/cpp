#include <iostream>

using namespace std;

int main(){

}

bool appendElement(int arr[], int &size, int capacity, int value){
    if (size >= capacity){
        return false;
    }
    arr[size] = value;
    size++;
    return true;
}